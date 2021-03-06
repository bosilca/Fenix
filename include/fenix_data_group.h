/*
//@HEADER
// ************************************************************************
//
//
//            _|_|_|_|  _|_|_|_|  _|      _|  _|_|_|  _|      _|
//            _|        _|        _|_|    _|    _|      _|  _|
//            _|_|_|    _|_|_|    _|  _|  _|    _|        _|
//            _|        _|        _|    _|_|    _|      _|  _|
//            _|        _|_|_|_|  _|      _|  _|_|_|  _|      _|
//
//
//
//
// Copyright (C) 2016 Rutgers University and Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author Marc Gamell, Eric Valenzuela, Keita Teranishi, Manish Parashar
//        and Michael Heroux
//
// Questions? Contact Keita Teranishi (knteran@sandia.gov) and
//                    Marc Gamell (mgamell@cac.rutgers.edu)
//
// ************************************************************************
//@HEADER
*/
#ifndef __FENIX_DATA_GROUP_H__
#define __FENIX_DATA_GROUP_H__

#include <mpi.h>
#include "fenix_data_member.h"
#include "fenix_data_packet.h"
#include "fenix_util.h"


#define __FENIX_DEFAULT_GROUP_SIZE 32

typedef struct __fenix_group_entry {
    int groupid;
    MPI_Comm comm;
    int comm_size;
    int current_rank;
    int in_rank;
    int out_rank;
    int timestart;
    int timestamp;
    int depth;
    int rank_separation;
    /* Subject to change */
    enum states state;
    int recovered;
    fenix_member_t *member;
} fenix_group_entry_t;

typedef struct __fenix_group {
    size_t count;
    size_t total_size;
    fenix_group_entry_t *group_entry;
} fenix_group_t;

typedef struct __group_entry_packet {
    int groupid;
    int timestamp;
    int depth;
    int rank_separation;
    enum states state;
} fenix_group_entry_packet_t;

fenix_group_t * __fenix_data_group_init();

void __fenix_data_group_destroy( fenix_group_t *fx_group );

void __fenix_data_group_reinit( fenix_group_t *g, fenix_two_container_packet_t packet);

void __fenix_ensure_group_capacity( fenix_group_t *g);

int __fenix_search_groupid( int key, fenix_group_t *group );

int __fenix_find_next_group_position( fenix_group_t *g );

#endif // FENIX_DATA_GROUP_H
