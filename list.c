#include "assignment3.h"//This cuts a line for some weird reason
#include <stdlib.h>
#include <stdio.h>

#define y 500000 //middle of number range, bigger gives better variation
/*
The actual code in this file is complete gibberish, I'm sorry about that. I made comments describing the functions in readable code.
I didn't actually test the code in the comments, it's just for explanation purposes.
The comments aren't always the exact same implementation as the real code.
*/

//Create-----------------------------------------------------------------------------
static SLnodePtr createSLlist(int m) {
  for (struct SLnode *SL = malloc(16); ((*SL).next = ((m != 1)? createSLlist(m-1):NULL), (*SL).key = ((*SL).next != NULL)? (rand()%((*(*SL).next).key-y+1)+y):((rand() % (y-1)) + y));) return SL;
}
/* Description of createSLlist:
static SLnodePtr createSLlist(int m) {
  struct SLnode *SL = malloc(sizeof (struct SLnode));
  if (m != 1) {
    (*SL).next = createSLlist(m-1);
    (*SL).key = (rand()%(*(*SL).next).key)+1;
  } else {
    (*SL).next = NULL;
    (*SL).key = (rand() % 499999) + 500000;
  }
  return SL;
}
*/

HBnodePtr createHBlist(int n ,int m) {
  for (struct HBnode *HB =(n == 0)? NULL:malloc(24), check = {rand() % (m + 1)}; (HB == NULL) || ((*HB).next = (createHBlist(n-1,m)), (*HB).bottom = (check.key == 0)? NULL:createSLlist(check.key), (*HB).key = 1+(((*HB).next == NULL)? (rand() % (y-1)):(rand() % (*(*HB).next).key)));) return HB;
}

/* Description of createHBlist:
HBnodePtr createHBlist(int n ,int m) {
  struct HBnode *HB;
  if (n == 0) {
    HB = NULL;
  } else {
    HB = malloc(sizeof (struct HBnode));
    int x = rand() % (m + 1);
    (*HB).next = createHBlist(n - 1, m);

    if (x != 0)
      (*HB).bottom = createSLlist(x);
    else
      (*HB).bottom = NULL;

    if ((*HB).next == NULL && (*HB).bottom == NULL)
      (*HB).key = (rand() % 499999)+500000;
    else if ((*HB).next == NULL)
      (*HB).key = (rand() % (*(*HB).bottom).key) + 1;
    else if ((*HB).bottom == NULL)
      (*HB).key = (rand() % (*(*HB).next).key) + 1;
    else if ((*(*HB).next).key > (*(*HB).bottom).key)
      (*HB).key = (rand() % (*(*HB).bottom).key) + 1;
    else
      (*HB).key = (rand() % (*(*HB).next).key) + 1;
  }

  return HB;
}
*/

//Flatten------------------------------------------------------------------------------
SLnodePtr flattenList(const HBnodePtr L){
  struct SLnode *SLstart = (L == NULL || (*L).next == NULL)? NULL:flattenList((*L).next);
  for (struct SLnode *SLlook = (L != NULL)? (*L).bottom:NULL, check = {(L != NULL)}, num = {-1,NULL}; ((check.key) && ((check.key = 0) || (num.key = (*L).key))) || ((SLlook != NULL) && (num.key = (*SLlook).key) && ((SLlook = (*SLlook).next) || 1)); ) for (struct SLnode S = {0, SLstart}, *SL = &S, *done = malloc(16); ((((*SL).next != NULL)? (*(*SL).next).key:1e99) < num.key) || (((*done).key = num.key, (*done).next = (*SL).next, (*SL).next = done) && !(SLstart = (SL == &S)? done:SLstart));) SL = (*SL).next;
  return SLstart;
}
/* Description of flattenList:
SLnodePtr flattenList(const HBnodePtr L){
  struct SLnode *SLstart;
  struct SLnode *SLlook;

  if (L == NULL)
    return NULL;
  else {
    struct SLnode temp = {0, (*L).bottom};
    SLlook = &temp;
  }

  if ((*L).next != NULL)
    SLstart = flattenList((*L).next);
  else
    SLstart = NULL;

  int num = (*L).key;

  for (;SLlook != NULL; num = (SLlook != NULL)? (*SLlook).key:10000000){
    if (SLstart == NULL){
      struct SLnode *done = malloc(sizeof (struct SLnode));
      (*done).key = num;
      (*done).next = NULL;
      SLstart = done;
    } else {
      struct SLnode tmp = {0, SLstart};
      struct SLnode *SL = &tmp;
      for (; ((*SL).next != NULL) && ((*(*SL).next).key < num);  SL = (*SL).next);
      struct SLnode *done = malloc(sizeof (struct SLnode));
      (*done).key = num;
      (*done).next = (*SL).next;
      if ((*SL).next == SLstart)
        SLstart = done;
      else
        (*SL).next = done;
    }
    SLlook = (*SLlook).next;
  }

  return SLstart;
}
*/

//Free---------------------------------------------------------------------------------
void freeSLlist(SLnodePtr L) {
  (L == NULL || (*L).next == NULL)? :(freeSLlist((*L).next));
  (L == NULL)? :free(L);
}

void freeHBlist(HBnodePtr L) {
  for(struct HBnode *next = L; L != NULL; L = next) {
    next = (*L).next;
    freeSLlist((*L).bottom);
    free(L);
  }
}

//Print----------------------------------------------------------------------------------
void printSLlist(const SLnodePtr L) {
  for (struct SLnode *next = L; next != NULL;next = (*next).next)
    printf("%-6d ", (*next).key);
}

void printHBlist(const HBnodePtr L) {
  for (struct HBnode *nextHB = L; nextHB != NULL; nextHB = (*nextHB).next) {
    printf("\n%6d -> ", ((*nextHB).key));
    printSLlist((*nextHB).bottom);
  }
}
