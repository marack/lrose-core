/*
 * movie_pu_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `movie_pu.G'.
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
#include <gcm.h>
#include <group.h>
#include "movie_pu_ui.h"

/*
 * Initialize an instance of object `movie_pu'.
 */
movie_pu_movie_pu_objects *
movie_pu_movie_pu_objects_initialize(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	if (!ip && !(ip = (movie_pu_movie_pu_objects *) calloc(1, sizeof (movie_pu_movie_pu_objects))))
		return (movie_pu_movie_pu_objects *) NULL;
	if (!ip->movie_pu)
		ip->movie_pu = movie_pu_movie_pu_movie_pu_create(ip, owner);
	if (!ip->movie_cp)
		ip->movie_cp = movie_pu_movie_pu_movie_cp_create(ip, ip->movie_pu);
	if (!ip->start_time_tx)
		ip->start_time_tx = movie_pu_movie_pu_start_time_tx_create(ip, ip->movie_cp);
	if (!ip->time_interval_tx)
		ip->time_interval_tx = movie_pu_movie_pu_time_interval_tx_create(ip, ip->movie_cp);
	if (!ip->min_msg)
		ip->min_msg = movie_pu_movie_pu_min_msg_create(ip, ip->movie_cp);
	if (!ip->fcast_per_tx)
		ip->fcast_per_tx = movie_pu_movie_pu_fcast_per_tx_create(ip, ip->movie_cp);
	if (!ip->facst_time_usits_msg)
		ip->facst_time_usits_msg = movie_pu_movie_pu_facst_time_usits_msg_create(ip, ip->movie_cp);
	if (!ip->end_frame_tx)
		ip->end_frame_tx = movie_pu_movie_pu_end_frame_tx_create(ip, ip->movie_cp);
	if (!ip->st_frame_tx)
		ip->st_frame_tx = movie_pu_movie_pu_st_frame_tx_create(ip, ip->movie_cp);
	if (!ip->msg1)
		ip->msg1 = movie_pu_movie_pu_msg1_create(ip, ip->movie_cp);
	if (!ip->movie_type_st)
		ip->movie_type_st = movie_pu_movie_pu_movie_type_st_create(ip, ip->movie_cp);
	if (!ip->start_st)
		ip->start_st = movie_pu_movie_pu_start_st_create(ip, ip->movie_cp);
	if (!ip->movie_dwell_sl)
		ip->movie_dwell_sl = movie_pu_movie_pu_movie_dwell_sl_create(ip, ip->movie_cp);
	if (!ip->movie_speed_sl)
		ip->movie_speed_sl = movie_pu_movie_pu_movie_speed_sl_create(ip, ip->movie_cp);
	if (!ip->movie_frame_sl)
		ip->movie_frame_sl = movie_pu_movie_pu_movie_frame_sl_create(ip, ip->movie_cp);
	if (!ip->fr_begin_msg)
		ip->fr_begin_msg = movie_pu_movie_pu_fr_begin_msg_create(ip, ip->movie_cp);
	if (!ip->group2)
		ip->group2 = movie_pu_movie_pu_group2_create(ip, ip->movie_cp);
	window_fit(ip->movie_cp);
	
	window_fit(ip->movie_pu);
	
	xv_set(ip->movie_cp,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		NULL);
	return ip;
}

/*
 * Create object `movie_pu' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_pu_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME_CMD,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 286,
		XV_HEIGHT, 182,
		XV_LABEL, "MOVIE CONTROLS",
		XV_SHOW, FALSE,
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, FALSE,
		FRAME_CMD_PUSHPIN_IN, TRUE,
		NULL);
	xv_set(xv_get(obj, FRAME_CMD_PANEL), WIN_SHOW, FALSE, NULL);
	return obj;
}

/*
 * Create object `movie_cp' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_cp_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
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
	gcm_initialize_colors(obj, "Green Yellow", NULL);
	return obj;
}

/*
 * Create object `start_time_tx' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_start_time_tx_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	start_time_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 1,
		XV_Y, 4,
		PANEL_VALUE_DISPLAY_LENGTH, 16,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Movie Loop Starts at:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, start_time_proc,
		NULL);
	return obj;
}

/*
 * Create object `time_interval_tx' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_time_interval_tx_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	time_interv_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 1,
		XV_Y, 22,
		PANEL_VALUE_DISPLAY_LENGTH, 7,
		PANEL_VALUE_STORED_LENGTH, 20,
		PANEL_LABEL_STRING, "Movie Frame Time Interval:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, time_interv_proc,
		NULL);
	return obj;
}

/*
 * Create object `min_msg' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_min_msg_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 254,
		XV_Y, 24,
		PANEL_LABEL_STRING, "min",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `fcast_per_tx' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_fcast_per_tx_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	set_fcast_period_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 1,
		XV_Y, 40,
		PANEL_VALUE_DISPLAY_LENGTH, 7,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Realtime-Look into Future:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, set_fcast_period_proc,
		NULL);
	return obj;
}

/*
 * Create object `facst_time_usits_msg' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_facst_time_usits_msg_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 254,
		XV_Y, 42,
		PANEL_LABEL_STRING, "min",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `end_frame_tx' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_end_frame_tx_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	end_frame_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_NUMERIC_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 1,
		XV_Y, 58,
		PANEL_VALUE_DISPLAY_LENGTH, 3,
		PANEL_VALUE_STORED_LENGTH, 32,
		PANEL_LABEL_STRING, "Number of Frames",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_MAX_VALUE, 128,
		PANEL_MIN_VALUE, 1,
		PANEL_VALUE, 0,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, end_frame_proc,
		NULL);
	return obj;
}

/*
 * Create object `st_frame_tx' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_st_frame_tx_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	start_frame_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_NUMERIC_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 194,
		XV_Y, 60,
		PANEL_VALUE_DISPLAY_LENGTH, 1,
		PANEL_VALUE_STORED_LENGTH, 32,
		PANEL_LABEL_STRING, "F",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_MAX_VALUE, 128,
		PANEL_MIN_VALUE, 1,
		PANEL_VALUE, 0,
		XV_SHOW, FALSE,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, start_frame_proc,
		NULL);
	return obj;
}

/*
 * Create object `msg1' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_msg1_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 2,
		XV_Y, 76,
		PANEL_LABEL_STRING, "**********************************************",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `movie_type_st' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_type_st_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern void		movie_type_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 88,
		PANEL_CHOICE_NROWS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_CHOOSE_NONE, FALSE,
		PANEL_NOTIFY_PROC, movie_type_proc,
		PANEL_CHOICE_STRINGS,
			"Real Time",
			"Archive",
			NULL,
		NULL);
	return obj;
}

/*
 * Create object `start_st' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_start_st_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern void		movie_start_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 176,
		XV_Y, 88,
		PANEL_CHOICE_NROWS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_CHOOSE_NONE, FALSE,
		PANEL_NOTIFY_PROC, movie_start_proc,
		PANEL_CHOICE_STRINGS,
			"Stop",
			"Start",
			NULL,
		NULL);
	return obj;
}

/*
 * Create object `movie_dwell_sl' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_dwell_sl_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern void		movie_delay_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_SLIDER,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 115,
		PANEL_SLIDER_WIDTH, 30,
		PANEL_TICKS, 0,
		PANEL_DIRECTION, PANEL_HORIZONTAL,
		PANEL_SLIDER_END_BOXES, FALSE,
		PANEL_SHOW_RANGE, TRUE,
		PANEL_SHOW_VALUE, FALSE,
		PANEL_MIN_VALUE, 0,
		PANEL_MAX_VALUE, 10,
		PANEL_MIN_VALUE_STRING, "End Delay",
		PANEL_MAX_VALUE_STRING, " ",
		PANEL_VALUE, 0,
		PANEL_NOTIFY_PROC, movie_delay_proc,
		NULL);
	return obj;
}

/*
 * Create object `movie_speed_sl' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_speed_sl_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern void		movie_speed_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_SLIDER,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 152,
		XV_Y, 115,
		PANEL_SLIDER_WIDTH, 40,
		PANEL_TICKS, 0,
		PANEL_DIRECTION, PANEL_HORIZONTAL,
		PANEL_SLIDER_END_BOXES, FALSE,
		PANEL_SHOW_RANGE, TRUE,
		PANEL_SHOW_VALUE, FALSE,
		PANEL_MIN_VALUE, 0,
		PANEL_MAX_VALUE, 30,
		PANEL_MIN_VALUE_STRING, "Slow",
		PANEL_MAX_VALUE_STRING, "Fast",
		PANEL_VALUE, 0,
		PANEL_NOTIFY_PROC, movie_speed_proc,
		NULL);
	return obj;
}

/*
 * Create object `movie_frame_sl' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_movie_frame_sl_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	extern void		movie_frame_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_SLIDER,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 139,
		PANEL_SLIDER_WIDTH, 100,
		PANEL_TICKS, 0,
		PANEL_LABEL_STRING, "Frame",
		PANEL_DIRECTION, PANEL_HORIZONTAL,
		PANEL_SLIDER_END_BOXES, TRUE,
		PANEL_SHOW_RANGE, TRUE,
		PANEL_SHOW_VALUE, TRUE,
		PANEL_MIN_VALUE, 0,
		PANEL_MAX_VALUE, 100,
		PANEL_VALUE, 0,
		PANEL_NOTIFY_PROC, movie_frame_proc,
		NULL);
	return obj;
}

/*
 * Create object `fr_begin_msg' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_fr_begin_msg_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 163,
		PANEL_LABEL_STRING, "FRAME TIME:",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `group2' in the specified instance.
 */
Xv_opaque
movie_pu_movie_pu_group2_create(ip, owner)
	movie_pu_movie_pu_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, GROUP,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 3,
		XV_Y, 88,
		GROUP_TYPE, GROUP_NONE,
		GROUP_MEMBERS,
			ip->movie_type_st,
			ip->start_st,
			ip->movie_dwell_sl,
			ip->movie_speed_sl,
			ip->movie_frame_sl,
			ip->fr_begin_msg,
			NULL,
		NULL);
	return obj;
}
