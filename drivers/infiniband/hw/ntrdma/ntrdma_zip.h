/*
 * Copyright (c) 2014, 2015 EMC Corporation.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NTRDMA_ZIP_H
#define NTRDMA_ZIP_H

#include "ntrdma_sg.h"

struct ntrdma_pd;
struct ntrdma_rpd;

/* Append dma requests from src entries in pd to dst entries in rpd */
int ntrdma_zip_rdma(struct ntrdma_dev *dev, void *req, u32 *rdma_len,
		    struct ntrdma_wr_sge *dst_sg_list,
		    struct ntrdma_wr_sge *src_sg_list,
		    u32 dst_sg_count, u32 src_sg_count,
		    bool rdma_read);

/* Sync incoming data to dst entries in pd for the cpu */
int ntrdma_zip_sync(struct ntrdma_dev *dev,
		    struct ntrdma_wr_sge *dst_sg_list,
		    u32 dst_sg_count);

#endif

