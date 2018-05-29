/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
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
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program MdvStats
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("Program name: MdvStats");
    tt->comment_text = tdrpStrDup("MdvStats computes the statistic values from a series of MDV files. The result is stored in a serials of MDV files, with each file indicates each statistics. The usage is 'MdvMedian -params params_file'.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUG AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug message will be printed appropriately.");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In ARCHIVE mode, the program moves through the data between the start and end times. In FILELIST mode, it moves through the list of file names specified.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[1].val = FILELIST;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_url_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url_dir");
    tt->descr = tdrpStrDup("URL directory for input data.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_url_dir - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://dtra-c2-ppio:0:mdv/NH/");
    tt++;
    
    // Parameter 'input_files'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_files");
    tt->descr = tdrpStrDup("FILELIST mode only. A list of file path need to be read in.");
    tt->help = tdrpStrDup("The program moves through the list and calculates the statistics needed.");
    tt->array_offset = (char *) &_input_files - &_start_;
    tt->array_n_offset = (char *) &input_files_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("19850101/000000.mdv");
      tt->array_vals[1].s = tdrpStrDup("19860101/000000.mdv");
    tt++;
    
    // Parameter 'start_date_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("start_date_time");
    tt->descr = tdrpStrDup("Start date time string.");
    tt->help = tdrpStrDup("ARCHIVE mode only. Start date time for data requested. Format is YYYY MM DD HH MM SS");
    tt->val_offset = (char *) &start_date_time - &_start_;
    tt->single_val.s = tdrpStrDup("1985 01 01 00 00 00");
    tt++;
    
    // Parameter 'end_date_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("end_date_time");
    tt->descr = tdrpStrDup("End date time string.");
    tt->help = tdrpStrDup("ARCHIVE mode only. End date time for data request. Format is YYYY MM DD HH MM SS");
    tt->val_offset = (char *) &end_date_time - &_start_;
    tt->single_val.s = tdrpStrDup("1986 01 01 00 00 00");
    tt++;
    
    // Parameter 'data_collection_type'
    // ctype is '_data_collection_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("data_collection_type");
    tt->descr = tdrpStrDup("Set data collection type, over the years, days or hours.");
    tt->help = tdrpStrDup("REALTIME and ARCHIVE mode only. Given start date time and end date time, move through files:\n YEARLY: over the years, at the same month, day and hour.\n DAYLY: over the days, at the same year, month and hour.\n HOURLY: over the hours, at the same year, month and day.\n ALL: move through all files between start and end date time.");
    tt->val_offset = (char *) &data_collection_type - &_start_;
    tt->enum_def.name = tdrpStrDup("data_collection_type_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("YEARLY");
      tt->enum_def.fields[0].val = YEARLY;
      tt->enum_def.fields[1].name = tdrpStrDup("DAYLY");
      tt->enum_def.fields[1].val = DAYLY;
      tt->enum_def.fields[2].name = tdrpStrDup("HOURLY");
      tt->enum_def.fields[2].val = HOURLY;
      tt->enum_def.fields[3].name = tdrpStrDup("ALL");
      tt->enum_def.fields[3].val = ALL;
    tt->single_val.e = YEARLY;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("COMPUTING THE STATISTICS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'fields_stats'
    // ctype is '_field_stats_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("fields_stats");
    tt->descr = tdrpStrDup("Fields and statistics information.");
    tt->help = tdrpStrDup("Fields and statistics to calculate. Make sure there are no duplicated fields here. Use short field names.");
    tt->array_offset = (char *) &_fields_stats - &_start_;
    tt->array_n_offset = (char *) &fields_stats_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(field_stats_t);
    tt->array_n = 6;
    tt->struct_def.name = tdrpStrDup("field_stats_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_fields_stats->field_name - (char *) _fields_stats;
      tt->struct_def.fields[1].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[1].fname = tdrpStrDup("std_dev");
      tt->struct_def.fields[1].ptype = BOOL_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_fields_stats->std_dev - (char *) _fields_stats;
      tt->struct_def.fields[2].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[2].fname = tdrpStrDup("mean");
      tt->struct_def.fields[2].ptype = BOOL_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_fields_stats->mean - (char *) _fields_stats;
      tt->struct_def.fields[3].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[3].fname = tdrpStrDup("min");
      tt->struct_def.fields[3].ptype = BOOL_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_fields_stats->min - (char *) _fields_stats;
      tt->struct_def.fields[4].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[4].fname = tdrpStrDup("max");
      tt->struct_def.fields[4].ptype = BOOL_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_fields_stats->max - (char *) _fields_stats;
      tt->struct_def.fields[5].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[5].fname = tdrpStrDup("sum");
      tt->struct_def.fields[5].ptype = BOOL_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_fields_stats->sum - (char *) _fields_stats;
    tt->n_struct_vals = 36;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("Temp");
      tt->struct_vals[1].b = pTRUE;
      tt->struct_vals[2].b = pTRUE;
      tt->struct_vals[3].b = pTRUE;
      tt->struct_vals[4].b = pTRUE;
      tt->struct_vals[5].b = pFALSE;
      tt->struct_vals[6].s = tdrpStrDup("RH");
      tt->struct_vals[7].b = pTRUE;
      tt->struct_vals[8].b = pTRUE;
      tt->struct_vals[9].b = pTRUE;
      tt->struct_vals[10].b = pTRUE;
      tt->struct_vals[11].b = pFALSE;
      tt->struct_vals[12].s = tdrpStrDup("U");
      tt->struct_vals[13].b = pTRUE;
      tt->struct_vals[14].b = pTRUE;
      tt->struct_vals[15].b = pTRUE;
      tt->struct_vals[16].b = pTRUE;
      tt->struct_vals[17].b = pFALSE;
      tt->struct_vals[18].s = tdrpStrDup("V");
      tt->struct_vals[19].b = pTRUE;
      tt->struct_vals[20].b = pTRUE;
      tt->struct_vals[21].b = pTRUE;
      tt->struct_vals[22].b = pTRUE;
      tt->struct_vals[23].b = pFALSE;
      tt->struct_vals[24].s = tdrpStrDup("W");
      tt->struct_vals[25].b = pTRUE;
      tt->struct_vals[26].b = pTRUE;
      tt->struct_vals[27].b = pTRUE;
      tt->struct_vals[28].b = pTRUE;
      tt->struct_vals[29].b = pFALSE;
      tt->struct_vals[30].s = tdrpStrDup("pressure");
      tt->struct_vals[31].b = pTRUE;
      tt->struct_vals[32].b = pTRUE;
      tt->struct_vals[33].b = pTRUE;
      tt->struct_vals[34].b = pTRUE;
      tt->struct_vals[35].b = pFALSE;
    tt++;
    
    // Parameter 'covariance_fields'
    // ctype is '_covariance_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("covariance_fields");
    tt->descr = tdrpStrDup("Covariance information.");
    tt->help = tdrpStrDup("Calculates covariance for fields. Use short field names");
    tt->array_offset = (char *) &_covariance_fields - &_start_;
    tt->array_n_offset = (char *) &covariance_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(covariance_t);
    tt->array_n = 3;
    tt->struct_def.name = tdrpStrDup("covariance_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name1");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_covariance_fields->field_name1 - (char *) _covariance_fields;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("field_name2");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_covariance_fields->field_name2 - (char *) _covariance_fields;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("U");
      tt->struct_vals[1].s = tdrpStrDup("V");
      tt->struct_vals[2].s = tdrpStrDup("V");
      tt->struct_vals[3].s = tdrpStrDup("W");
      tt->struct_vals[4].s = tdrpStrDup("U");
      tt->struct_vals[5].s = tdrpStrDup("W");
    tt++;
    
    // Parameter 'use_absolute_values'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_absolute_values");
    tt->descr = tdrpStrDup("Use absolute values to calculate standard deviation and mean.");
    tt->help = tdrpStrDup("Using absolute values is helpful in finding outliers, especially for fields like U,V,W.");
    tt->val_offset = (char *) &use_absolute_values - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'stats_url_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("stats_url_dir");
    tt->descr = tdrpStrDup("Statistics files URL directory.");
    tt->help = tdrpStrDup("Statistics file is written to this URL directory. The file name is based on the time of the last file used.");
    tt->val_offset = (char *) &stats_url_dir - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://dtra-c2-ppio:0:mdv/NH/mdvstats");
    tt++;
    
    // Parameter 'compress_stats_fields'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("compress_stats_fields");
    tt->descr = tdrpStrDup("Flag indicating whether to compress the stats fields when writing them to disk.");
    tt->help = tdrpStrDup("Compressing the statistics files will save disk space, but will slow down the reading and writing of the files. ");
    tt->val_offset = (char *) &compress_stats_fields - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'output_data_set_info'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_data_set_info");
    tt->descr = tdrpStrDup("Data set information.");
    tt->help = tdrpStrDup("This info will be placed in the MDV master header for documentation purposes.");
    tt->val_offset = (char *) &output_data_set_info - &_start_;
    tt->single_val.s = tdrpStrDup("Statistics data calculated by MdvStats.");
    tt++;
    
    // Parameter 'data_transformation_type'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_transformation_type");
    tt->descr = tdrpStrDup("Data transformation type.");
    tt->help = tdrpStrDup("No more than 15 characters. This information will be placed in the MDV field headers for documentation and search purposes.");
    tt->val_offset = (char *) &data_transformation_type - &_start_;
    tt->single_val.s = tdrpStrDup("1hrby1dby21yr");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
