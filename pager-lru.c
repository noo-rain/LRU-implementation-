/*
 * File: pager-lru.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains an lru pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    
    /* This file contains the stub for an LRU pager */
    /* You may need to add/remove/modify any part of this file */

    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    /* Local vars */
    int proctmp;
    int pagetmp;
    int proc;
    int page;
    int pc;

    /* initialize static vars on first run */
    if(!initialized){
	for(proctmp=0; proctmp < MAXPROCESSES; proctmp++){
	    for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++){
		timestamps[proctmp][pagetmp] = 0; 
	    }
	}
	initialized = 1;
    }
    
    /* TODO: Implement LRU Paging */

	/* Trivial paging strategy */
    /* Select first active process */ 
    for(proc=0; proc<MAXPROCESSES; proc++) { 
	/* Is process active? */
	if(q[proc].active) {
	    pc = q[proc].pc; 		        // program counter for process
	    page = pc/PAGESIZE; 		// page the program counter needs
	    /* Is page swaped-out? */
	    if(!q[proc].pages[page]) {
		/* Try to swap in */
		if(!pagein(proc,page)) {
		    /* If swapping fails, swap out another page */
		int page_index = 0;
		int initial_value = 5000; //we want to set this to a high initial value
		int i;
		for(i = 0; i < MAXPROCPAGES; i++) { //loop through the pages in the process 
			if (initial_value < timestamps[proc][i] && q[proc].pages[i]) {
//if the initial value is less than the timestamp
				initial_value = timestamps[proc][i];
//set the intitial value to the timestamp
				page_index = i;
//set the page index to whatever i index it's at
			}

		}

		pageout(proc, page_index);
//call page out with that index, it will swap out the oldest page
		}
			if(pagein(proc,page)){ //once pageout() is called and we swapped out the page, we'll be left with an empty space, so we call pagein once again to swap that page in
			timestamps[proc][page] = tick;
//then we update the timestamps matrix
			}
	    }
	
    } 
} 


    /* advance time for next pageit iteration */
    tick++;
} 
