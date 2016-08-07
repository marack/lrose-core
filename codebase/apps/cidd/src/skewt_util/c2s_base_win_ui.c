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
/*
 * c2s_base_win_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `c2s_base_win.G'.
 * DO NOT EDIT BY HAND.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/canvas.h>
#include <xview/panel.h>
#include <xview/scrollbar.h>
#include <xview/svrimage.h>
#include <xview/termsw.h>
#include <xview/text.h>
#include <xview/tty.h>
#include <xview/xv_xrect.h>
#include <devguide/gcm.h>
#include "c2s_base_win_ui.h"

/*
 * Initialize an instance of object `c2s_bw'.
 */
c2s_base_win_c2s_bw_objects *
c2s_base_win_c2s_bw_objects_initialize(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	if (!ip && !(ip = (c2s_base_win_c2s_bw_objects *) calloc(1, sizeof (c2s_base_win_c2s_bw_objects))))
		return (c2s_base_win_c2s_bw_objects *) NULL;
	if (!ip->c2s_bw)
		ip->c2s_bw = c2s_base_win_c2s_bw_c2s_bw_create(ip, owner);
	if (!ip->controls1)
		ip->controls1 = c2s_base_win_c2s_bw_controls1_create(ip, ip->c2s_bw);
	if (!ip->info_msg)
		ip->info_msg = c2s_base_win_c2s_bw_info_msg_create(ip, ip->controls1);
	if (!ip->info_msg2)
		ip->info_msg2 = c2s_base_win_c2s_bw_info_msg2_create(ip, ip->controls1);
	if (!ip->def_gen_bt)
		ip->def_gen_bt = c2s_base_win_c2s_bw_def_gen_bt_create(ip, ip->controls1);
	if (!ip->gen_skewt_file_bt)
		ip->gen_skewt_file_bt = c2s_base_win_c2s_bw_gen_skewt_file_bt_create(ip, ip->controls1);
	if (!ip->slp_tx)
		ip->slp_tx = c2s_base_win_c2s_bw_slp_tx_create(ip, ip->controls1);
	return ip;
}

/*
 * Create object `c2s_bw' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_c2s_bw_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	Xv_opaque		c2s_bw_image;
	static unsigned short	c2s_bw_bits[] = {
#include "cidd_skewt.icon"
	};
	
	c2s_bw_image = xv_create(XV_NULL, SERVER_IMAGE,
		SERVER_IMAGE_DEPTH, 1,
		SERVER_IMAGE_BITS, c2s_bw_bits,
		XV_WIDTH, 64,
		XV_HEIGHT, 64,
		NULL);
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 162,
		XV_HEIGHT, 118,
		XV_LABEL, "Cidd SkewT",
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, FALSE,
		FRAME_ICON, xv_create(XV_NULL, ICON,
			ICON_IMAGE, c2s_bw_image,
			NULL),
		NULL);
	gcm_initialize_colors(obj, "Dim Gray", NULL);
	return obj;
}

/*
 * Create object `controls1' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_controls1_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		WIN_BORDER, FALSE,
		NULL);
	gcm_initialize_colors(obj, "Dim Gray", NULL);
	return obj;
}

/*
 * Create object `info_msg' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_info_msg_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 16,
		XV_Y, 0,
		PANEL_ITEM_COLOR, gcm_color_index("White"),
		PANEL_LABEL_STRING, "Select point on plot",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `info_msg2' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_info_msg2_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 23,
		XV_Y, 18,
		PANEL_ITEM_COLOR, gcm_color_index("White"),
		PANEL_LABEL_STRING, "then push button",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `def_gen_bt' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_def_gen_bt_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	extern void		gen_plot_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 6,
		XV_Y, 42,
		PANEL_LABEL_STRING, "Generate Skew T Plot",
		PANEL_NOTIFY_PROC, gen_plot_proc,
		NULL);
	return obj;
}

/*
 * Create object `gen_skewt_file_bt' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_gen_skewt_file_bt_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	extern void		gen_file_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 69,
		PANEL_LABEL_STRING, "Generate CLASS File",
		PANEL_NOTIFY_PROC, gen_file_proc,
		NULL);
	return obj;
}

/*
 * Create object `slp_tx' in the specified instance.
 */
Xv_opaque
c2s_base_win_c2s_bw_slp_tx_create(ip, owner)
	c2s_base_win_c2s_bw_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	slp_tx_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 6,
		XV_Y, 98,
		PANEL_VALUE_DISPLAY_LENGTH, 8,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_ITEM_COLOR, gcm_color_index("Light Gray"),
		PANEL_LABEL_STRING, "SLP (mbar):",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_VALUE, "1000",
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, slp_tx_proc,
		NULL);
	return obj;
}
