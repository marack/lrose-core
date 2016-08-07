// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program GenPoly2Mdv
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
using namespace std;

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
    tt->comment_hdr = tdrpStrDup("GenPoly2Mdv reads the SPDB GenPoly object written by\n and writes gridded MDV files with\nThe program is run in archive mode with start\nand end times specified in the following manner :\n\nStormInit2Field -start YYYY MM DD hh mm ss -end YYYY MM DD hh mm ss\nwith quotes around the YYYY MM DD hh mm ss arguments.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Set to true to print debug messages");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Instance to check in to Procmap with");
    tt->help = tdrpStrDup("Set to something unique.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'spdb_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdb_url");
    tt->descr = tdrpStrDup("Input SPDB URL");
    tt->help = tdrpStrDup("The GenPoly structures that drive the program\nare read from this SPDB URL.");
    tt->val_offset = (char *) &spdb_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::spdb/genPoly");
    tt++;
    
    // Parameter 'start_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("start_time");
    tt->descr = tdrpStrDup("yyyymmddhhMMss");
    tt->help = tdrpStrDup("Set for ARCHIVE mode only.");
    tt->val_offset = (char *) &start_time - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'end_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("end_time");
    tt->descr = tdrpStrDup("yyyymmddhhMMss");
    tt->help = tdrpStrDup("Set for ARCHIVE mode only.");
    tt->val_offset = (char *) &end_time - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("TRIGGER MODE");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'triggerMode'
    // ctype is '_triggerMode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("triggerMode");
    tt->descr = tdrpStrDup("Decide how the program is triggered.");
    tt->help = tdrpStrDup("The program can be triggered in one of four ways.\n\n (1) TRIGGER_ARCHIVE - the program is run in archive mode\n     on existing data. The start and end times are determined\n     on the command line with -start and -end in the usual way.\n     Specifying these argumnets automatically invokes this mode.     The time step is determined by the timeStep parameter.\n\n (2) TRIGGER_INTERVAL - the program wakes up at regular intervals and\n     runs. These intervals are determined by the timeStep parameter.     This enables the program to run in realtime on a machine remote\n     from where the data are.\n\n (3) TRIGGER_LDATAINFO - the program triggers directly from\n     the titan output using the DsInputPath class. The timeStep\n     parameter is ignored. This has the advantage that the program\n     is triggered directly by Titan; but it does mean that it must\n     run on the same machine as the Titan system (since DsInputPath\n     is inherrently a local device at the time of writing).\n (4) TRIGGER_FMQ - the program triggers on a nowcast FMQ sent\n     by the StormInitDetect process.");
    tt->val_offset = (char *) &triggerMode - &_start_;
    tt->enum_def.name = tdrpStrDup("triggerMode_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TRIGGER_ARCHIVE");
      tt->enum_def.fields[0].val = TRIGGER_ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("TRIGGER_INTERVAL");
      tt->enum_def.fields[1].val = TRIGGER_INTERVAL;
      tt->enum_def.fields[2].name = tdrpStrDup("TRIGGER_LDATAINFO");
      tt->enum_def.fields[2].val = TRIGGER_LDATAINFO;
      tt->enum_def.fields[3].name = tdrpStrDup("TRIGGER_FMQ");
      tt->enum_def.fields[3].val = TRIGGER_FMQ;
    tt->single_val.e = TRIGGER_LDATAINFO;
    tt++;
    
    // Parameter 'trigger_fmq'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("trigger_fmq");
    tt->descr = tdrpStrDup("FMQ to trigger from if triggerMode is TRIGGER_FMQ.");
    tt->help = tdrpStrDup("FMQ will be sent by ??");
    tt->val_offset = (char *) &trigger_fmq - &_start_;
    tt->single_val.s = tdrpStrDup("fmqp:://localhost::/fmq/??");
    tt++;
    
    // Parameter 'trigger_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("trigger_dir");
    tt->descr = tdrpStrDup("Directory to trigger from if triggerMode is TRIGGER_LDATAINFO.");
    tt->help = tdrpStrDup("Note that the data are not read from here - this is used\nsoley for triggering. Data are always read from spdb GenPoly url.");
    tt->val_offset = (char *) &trigger_dir - &_start_;
    tt->single_val.s = tdrpStrDup("/Some/Directory/Structure");
    tt++;
    
    // Parameter 'max_valid_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_valid_age");
    tt->descr = tdrpStrDup("Maximum valid age if triggerMode is TRIGGER_LDATAINFO, seconds.\n");
    tt->help = tdrpStrDup("The default should be fine.");
    tt->val_offset = (char *) &max_valid_age - &_start_;
    tt->single_val.l = 1800;
    tt++;
    
    // Parameter 'trigger_interval'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("trigger_interval");
    tt->descr = tdrpStrDup("Trigger interval, seconds.");
    tt->help = tdrpStrDup("Program wakes up every interval to process data in\nREALTIME mode. In ARCHIVE mode, start and end times are\nspecified on the command line. The program begins at the\nstart time and increments its way to the end time in steps of\nTriggerInterval.");
    tt->val_offset = (char *) &trigger_interval - &_start_;
    tt->single_val.l = 300;
    tt++;
    
    // Parameter 'lookback'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("lookback");
    tt->descr = tdrpStrDup("Time to look back on triggering, seconds.");
    tt->help = tdrpStrDup("While the TriggerInterval parameter defines how often the\nprogram wakes up to process data, the LookBack parameter defines\nhow far back in time the program will look for data when it does\nwake up.\n\nThe reason LookBack is not identical to TriggerInterval\nis that the ltg data may take some time to arrive. Thus, making\nLookBack larger than TriggerInterval allows for some temporal\noverlap to ensure that all data are processed.");
    tt->val_offset = (char *) &lookback - &_start_;
    tt->single_val.l = 360;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("GRID GEOMETRY");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_projection'
    // ctype is '_output_projection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_projection");
    tt->descr = tdrpStrDup("Projection of output grid.");
    tt->help = tdrpStrDup("FLAT - (x,y) Cartesian data in km from a given origin.\nLATLON - lat/lon grid with constant grid spacing.\n");
    tt->val_offset = (char *) &output_projection - &_start_;
    tt->enum_def.name = tdrpStrDup("output_projection_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("OUTPUT_PROJ_FLAT");
      tt->enum_def.fields[0].val = OUTPUT_PROJ_FLAT;
      tt->enum_def.fields[1].name = tdrpStrDup("OUTPUT_PROJ_LATLON");
      tt->enum_def.fields[1].val = OUTPUT_PROJ_LATLON;
      tt->enum_def.fields[2].name = tdrpStrDup("OUTPUT_PROJ_LAMBERT");
      tt->enum_def.fields[2].val = OUTPUT_PROJ_LAMBERT;
    tt->single_val.e = OUTPUT_PROJ_FLAT;
    tt++;
    
    // Parameter 'output_origin'
    // ctype is '_output_origin_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_origin");
    tt->descr = tdrpStrDup("Origin of output grid.");
    tt->help = tdrpStrDup("Used with OUTPUT_PROJ_FLAT and OUTPUT_PROJ_LAMBERT.");
    tt->val_offset = (char *) &output_origin - &_start_;
    tt->struct_def.name = tdrpStrDup("output_origin_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("lat");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &output_origin.lat - (char *) &output_origin;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("lon");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &output_origin.lon - (char *) &output_origin;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 40;
      tt->struct_vals[1].d = -104;
    tt++;
    
    // Parameter 'output_rotation'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("output_rotation");
    tt->descr = tdrpStrDup("Rotation of output grid.");
    tt->help = tdrpStrDup("Used with OUTPUT_PROJ_FLAT.");
    tt->val_offset = (char *) &output_rotation - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = 0;
    tt->max_val.d = 360;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'output_std_parallels'
    // ctype is '_output_std_parallels_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_std_parallels");
    tt->descr = tdrpStrDup("Standard parallels of the output grid.");
    tt->help = tdrpStrDup("Used with OUTPUT_PROJ_LAMBERT only.");
    tt->val_offset = (char *) &output_std_parallels - &_start_;
    tt->struct_def.name = tdrpStrDup("output_std_parallels_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("lat_1");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &output_std_parallels.lat_1 - (char *) &output_std_parallels;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("lat_2");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &output_std_parallels.lat_2 - (char *) &output_std_parallels;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 20;
      tt->struct_vals[1].d = 45;
    tt++;
    
    // Parameter 'output_grid'
    // ctype is '_grid_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_grid");
    tt->descr = tdrpStrDup("Output grid parameters.");
    tt->help = tdrpStrDup("The grid params for the output grid.");
    tt->val_offset = (char *) &output_grid - &_start_;
    tt->struct_def.name = tdrpStrDup("grid_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("long");
      tt->struct_def.fields[0].fname = tdrpStrDup("nx");
      tt->struct_def.fields[0].ptype = LONG_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &output_grid.nx - (char *) &output_grid;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("ny");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &output_grid.ny - (char *) &output_grid;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("minx");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &output_grid.minx - (char *) &output_grid;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("miny");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &output_grid.miny - (char *) &output_grid;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("dx");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &output_grid.dx - (char *) &output_grid;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("dy");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &output_grid.dy - (char *) &output_grid;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].l = 300;
      tt->struct_vals[1].l = 300;
      tt->struct_vals[2].d = -149.5;
      tt->struct_vals[3].d = -149.5;
      tt->struct_vals[4].d = 1;
      tt->struct_vals[5].d = 1;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mdv_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("mdv_url");
    tt->descr = tdrpStrDup("Output MDV URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &mdv_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/polygon");
    tt++;
    
    // Parameter 'time_stamp_mode'
    // ctype is '_timestampMode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("time_stamp_mode");
    tt->descr = tdrpStrDup("Timestamp mode");
    tt->help = tdrpStrDup("To timestamp at start, middle or end of the window considered.");
    tt->val_offset = (char *) &time_stamp_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("timestampMode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TIMESTAMP_START");
      tt->enum_def.fields[0].val = TIMESTAMP_START;
      tt->enum_def.fields[1].name = tdrpStrDup("TIMESTAMP_MIDDLE");
      tt->enum_def.fields[1].val = TIMESTAMP_MIDDLE;
      tt->enum_def.fields[2].name = tdrpStrDup("TIMESTAMP_END");
      tt->enum_def.fields[2].val = TIMESTAMP_END;
    tt->single_val.e = TIMESTAMP_END;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }