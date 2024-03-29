#include "queue.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int createQueue(queue_t *pQueue, data_t data) {
  if (pQueue->pBack != NULL) {
    deleteQueue(pQueue);
  }
  node_t *pNew = (node_t *)malloc(sizeof(node_t));
  if (pNew == NULL) {
    return errno;
  }
  pQueue->pBack = pNew;
  if (pNew != NULL) {
    pNew->data      = data; /* copy input struct data */
    pNew->pNextNode = pNew;
  }
  return 0;
}

int emptyQueue(const queue_t *pQueue) { return pQueue->pBack == NULL; }

size_t sizeQueue(const queue_t *pQueue) {
  size_t size = 0;
  /* local pointer for traversing all nodes in queue */
  const node_t *pSize = pQueue->pBack;
  node_t       *pTemp = pSize;
  do {
    size++;
    pTemp = pTemp->pNextNode;
  } while (pTemp != pSize);

  return size;
}

data_t *frontQueue(const queue_t *pQueue) {
  data_t *pFrontData = NULL;
  if (!emptyQueue(pQueue)) {
    pFrontData = &(pQueue->pBack->pNextNode->data);
  }
  return pFrontData;
}

data_t *backQueue(const queue_t *pQueue) {
  data_t *pBackData = NULL;
  if (!emptyQueue(pQueue)) {
    pBackData = &(pQueue->pBack->data);
  }
  return pBackData;
}

int pushQueue(queue_t *pQueue, data_t data) {
  node_t *pNew = (node_t *)malloc(sizeof(node_t));
  if (pNew != NULL) {
    pNew->data               = data;
    pNew->pNextNode          = pQueue->pBack->pNextNode;
    pQueue->pBack->pNextNode = pNew;
    pQueue->pBack            = pNew;
    return 0;
  } else {
    return errno;
  }
}

void popQueue(queue_t *pQueue) {
  if (pQueue->pBack != NULL) {
    node_t *pDelete = pQueue->pBack->pNextNode;
    if (pDelete == pQueue->pBack) {
      /* size queue == 1 */
      pQueue->pBack = NULL;
    } else {
      pQueue->pBack->pNextNode = pDelete->pNextNode;
    }
    free(pDelete);
  }
}

void deleteQueue(queue_t *pQueue) {
  /* local pointer for traversing all nodes in queue */
  node_t *pDelete = pQueue->pBack;
  node_t *pNext   = NULL;
  int     count   = 0;
  do {
    pNext = pDelete->pNextNode;
    free(pDelete);
    pDelete = pNext;
    count++;
  } while (pDelete != pQueue->pBack);
  printf("Deleted %d nodes\n", count);
}

void showQueue(const queue_t *pQueue) {
  const node_t *pNext = pQueue->pBack;

  if (pNext == NULL) {
    printf("Queue is empty\n");
  } else {
    printf("Queue contains:\n");
    do {
      pNext = pNext->pNextNode;
      printf("pNode = %p  Data = '%d' '%s'\n"
             "                        pNextNode = %p\n",
             pNext, pNext->data.intVal, pNext->data.text, pNext->pNextNode);
    } while (pNext != pQueue->pBack);
  }
}
