/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
#ifndef	v_win_HEADER
#define	v_win_HEADER

/*
 * v_win_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `v_win.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;

extern Xv_opaque	v_win_v_field_mu_create(caddr_t, Xv_opaque);

typedef struct {
	Xv_opaque	v_win_pu;
	Xv_opaque	controls1;
	Xv_opaque	route_st;
	Xv_opaque	route_labels_st;
	Xv_opaque	dismiss_bt;
	Xv_opaque	route_msg;
	Xv_opaque	hazard_msg;
	Xv_opaque	canvas1;
} v_win_v_win_pu_objects;

extern v_win_v_win_pu_objects	*v_win_v_win_pu_objects_initialize(v_win_v_win_pu_objects *, Xv_opaque);

extern Xv_opaque	v_win_v_win_pu_v_win_pu_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_controls1_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_route_st_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_route_labels_st_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_dismiss_bt_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_route_msg_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_hazard_msg_create(v_win_v_win_pu_objects *, Xv_opaque);
extern Xv_opaque	v_win_v_win_pu_canvas1_create(v_win_v_win_pu_objects *, Xv_opaque);
#endif