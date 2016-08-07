/*******************************************
 * tstorms_spdb2symprod_tdrp.h
 *
 * TDRP header file for 'tstorms_spdb2symprod' module.
 *
 * Code for program tstorms_spdb2symprod
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _tstorms_spdb2symprod_tdrp_h
#define _tstorms_spdb2symprod_tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

typedef enum {
  SPEED_KMH = 0,
  SPEED_KNOTS = 1,
  SPEED_MPH = 2
} tstorms_spdb2symprod_speed_units_t;

typedef enum {
  DEBUG_OFF = 0,
  DEBUG_ERRORS = 1,
  DEBUG_MSGS = 2,
  DEBUG_ROUTINES = 3,
  DEBUG_ALL = 4
} tstorms_spdb2symprod_debug_t;

typedef enum {
  ELLIPSE_SHAPE = 0,
  POLYGON_SHAPE = 1
} tstorms_spdb2symprod_storm_shape;

typedef enum {
  LINETYPE_SOLID = 0,
  LINETYPE_DASH = 1,
  LINETYPE_DOT_DASH = 2
} tstorms_spdb2symprod_line_type_t;

typedef enum {
  CAPSTYLE_BUTT = 0,
  CAPSTYLE_NOT_LAST = 1,
  CAPSTYLE_PROJECTING = 2,
  CAPSTYLE_ROUND = 3
} tstorms_spdb2symprod_capstyle_t;

typedef enum {
  JOINSTYLE_BEVEL = 0,
  JOINSTYLE_MITER = 1,
  JOINSTYLE_ROUND = 2
} tstorms_spdb2symprod_joinstyle_t;

/*
 * typedef for main struct - tstorms_spdb2symprod_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug *****/

  tstorms_spdb2symprod_debug_t debug;

  /***** malloc_debug_level *****/

  long malloc_debug_level;

  /***** database_dir *****/

  char* database_dir;

  /***** product_label *****/

  char* product_label;

  /***** product_id *****/

  long product_id;

  /***** port *****/

  long port;

  /***** servmap_type *****/

  char* servmap_type;

  /***** servmap_subtype *****/

  char* servmap_subtype;

  /***** servmap_instance *****/

  char* servmap_instance;

  /***** realtime_avail *****/

  tdrp_bool_t realtime_avail;

  /***** valid_forecasts_only *****/

  tdrp_bool_t valid_forecasts_only;

  /***** plot_current *****/

  tdrp_bool_t plot_current;

  /***** plot_forecast *****/

  tdrp_bool_t plot_forecast;

  /***** forecast_lead_time *****/

  long forecast_lead_time;

  /***** forecast_dashed *****/

  tdrp_bool_t forecast_dashed;

  /***** storm_shape *****/

  tstorms_spdb2symprod_storm_shape storm_shape;

  /***** plot_trend *****/

  tdrp_bool_t plot_trend;

  /***** plot_speed *****/

  tdrp_bool_t plot_speed;

  /***** speed_units *****/

  tstorms_spdb2symprod_speed_units_t speed_units;

  /***** speed_round *****/

  tdrp_bool_t speed_round;

  /***** plot_top *****/

  tdrp_bool_t plot_top;

  /***** top_km *****/

  tdrp_bool_t top_km;

  /***** hull_smooth *****/

  tdrp_bool_t hull_smooth;

  /***** inner_bnd_multiplier *****/

  double inner_bnd_multiplier;

  /***** outer_bnd_multiplier *****/

  double outer_bnd_multiplier;

  /***** plot_vectors *****/

  tdrp_bool_t plot_vectors;

  /***** arrow_head_len *****/

  double arrow_head_len;

  /***** arrow_head_half_angle *****/

  double arrow_head_half_angle;

  /***** fixed_length_arrows *****/

  tdrp_bool_t fixed_length_arrows;

  /***** arrow_shaft_length *****/

  double arrow_shaft_length;

  /***** current_color *****/

  char* current_color;

  /***** forecast_color *****/

  char* forecast_color;

  /***** vector_color *****/

  char* vector_color;

  /***** text_color *****/

  char* text_color;

  /***** text_background_color *****/

  char* text_background_color;

  /***** text_font *****/

  char* text_font;

  /***** suggested_line_type *****/

  tstorms_spdb2symprod_line_type_t suggested_line_type;

  /***** suggested_line_width *****/

  long suggested_line_width;

  /***** suggested_capstyle *****/

  tstorms_spdb2symprod_capstyle_t suggested_capstyle;

  /***** suggested_joinstyle *****/

  tstorms_spdb2symprod_joinstyle_t suggested_joinstyle;

} tstorms_spdb2symprod_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * tstorms_spdb2symprod_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   tstorms_spdb2symprod_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int tstorms_spdb2symprod_tdrp_load_from_args(int argc, char **argv,
                                tstorms_spdb2symprod_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than tstorms_spdb2symprod_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   tstorms_spdb2symprod_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int tstorms_spdb2symprod_tdrp_load(char *param_file_path,
                      tstorms_spdb2symprod_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See tstorms_spdb2symprod_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int tstorms_spdb2symprod_tdrp_load_defaults(tstorms_spdb2symprod_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void tstorms_spdb2symprod_tdrp_sync(void);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

extern void tstorms_spdb2symprod_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void tstorms_spdb2symprod_tdrp_free_all(void);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int tstorms_spdb2symprod_tdrp_check_all_set(FILE *out);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int tstorms_spdb2symprod_tdrp_check_is_set(char *param_name);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int tstorms_spdb2symprod_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int tstorms_spdb2symprod_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *tstorms_spdb2symprod_tdrp_table(void);

/*************************************************************
 * tstorms_spdb2symprod_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *tstorms_spdb2symprod_tdrp_init(tstorms_spdb2symprod_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif
