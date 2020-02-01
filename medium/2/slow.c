/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>            
#include <stdint.h>           
#include <string.h>
#include <stdbool.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    uint32_t u32i     = 0;
    uint32_t u32num   = 0;
    bool     bIsCarry = false;
    bool     bIsSameL = false;

    struct ListNode *lcur = malloc( sizeof( struct ListNode ) );
    struct ListNode *lout = lcur;
    struct ListNode *lbig = NULL;

    // initial array
    lcur->next = NULL;
    memset( lout, 0x00, sizeof( struct ListNode ) );

    // calculate when both is not NULL
    while( true ) { 
        u32num = l1->val + l2->val;
        if( bIsCarry ) { 
            u32num++;
        }
        if( 10 <= u32num ) {
            u32num -= 10;
            bIsCarry = true;
        }
        else {
            bIsCarry = false;
        }
        lcur->val = u32num;

        if( NULL == l1->next && NULL == l2->next ) {
            bIsSameL = true;
            break;
        }
        else if( NULL == l1->next ) {
            bIsSameL = false;
            lbig = l2;
            break;
        }
        else if( NULL == l2->next ) {
            bIsSameL = false;
            lbig = l1;
            break;
        }
        else {
            lcur->next = malloc( sizeof( struct ListNode ) );
            lcur->next->next = NULL;
            lcur = lcur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    if( false == bIsSameL ) {
        lcur->next = malloc( sizeof( struct ListNode ) );
        lcur->next->next = NULL;
        lcur = lcur->next;
        lbig = lbig->next;

        while( true ) {
            u32num = lbig->val;
            if( bIsCarry ) {
                u32num++;
            }
            if( 10 <= u32num ) {
                u32num -= 10;
                bIsCarry = true;
            }
            else {
                bIsCarry = false;
            }
            lcur->val = u32num;
            if( NULL != lbig->next ) {
                lcur->next = malloc( sizeof( struct ListNode ) );
                lcur->next->next = NULL;
                lcur = lcur->next;
                lbig = lbig->next;
            }
            else if( bIsCarry ) {
                lcur->next = malloc( sizeof( struct ListNode ) );
                lcur->next->next = NULL;
                lcur = lcur->next;
                lcur->val = 1;
                break;
            }
            else {
                lcur->next = NULL;
                break;
            }
        }
    }
    else {
        if( bIsCarry ) { 
            lcur->next = malloc( sizeof( struct ListNode ) );
            lcur->next->next = NULL;
            lcur = lcur->next;
            lcur->val = 1;
        }
        lcur->next = NULL;                                                                                                                                                             
    }

    return lout;
}
