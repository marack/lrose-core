#ifndef	draw_pu_HEADER
#define	draw_pu_HEADER

/*
 * draw_pu_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `draw_pu.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;


typedef struct {
	Xv_opaque	draw_pu;
	Xv_opaque	controls2;
	Xv_opaque	type_st;
	Xv_opaque	serialno_tx;
	Xv_opaque	validtm_tx;
	Xv_opaque	minute_msg;
	Xv_opaque	label_tx;
	Xv_opaque	time_tx;
	Xv_opaque	url_tx;
	Xv_opaque	cancel_bt;
	Xv_opaque	ok_bt;
} draw_pu_draw_pu_objects;

extern draw_pu_draw_pu_objects	*draw_pu_draw_pu_objects_initialize(draw_pu_draw_pu_objects *, Xv_opaque);

extern Xv_opaque	draw_pu_draw_pu_draw_pu_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_controls2_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_type_st_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_serialno_tx_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_validtm_tx_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_minute_msg_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_label_tx_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_time_tx_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_url_tx_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_cancel_bt_create(draw_pu_draw_pu_objects *, Xv_opaque);
extern Xv_opaque	draw_pu_draw_pu_ok_bt_create(draw_pu_draw_pu_objects *, Xv_opaque);
#endif