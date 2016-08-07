// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1992 - 2012 
// ** University Corporation for Atmospheric Research(UCAR) 
// ** National Center for Atmospheric Research(NCAR) 
// ** Research Applications Laboratory(RAL) 
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA 
// ** 2012/3/18 17:24:52 
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program ChillSdbServer
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
        << "   [ -params path ] specify params file path\n"
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
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
    tt->comment_hdr = tdrpStrDup("ChillSdbServer reads data from a DsRadar queue, in NCAR/RAL format, reformats it into CHILL SDB (Standard Data Buffer) format, and serves it out via TCP.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
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
    
    // Parameter 'no_threads'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("no_threads");
    tt->descr = tdrpStrDup("Option to prevent server from using a thread per client.");
    tt->help = tdrpStrDup("For debugging purposes it it sometimes useful to suppress the use of threads. Set no_threads to TRUE for this type of debugging.");
    tt->val_offset = (char *) &no_threads - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance.");
    tt->help = tdrpStrDup("Used for procmap registration and auto restarting. If an empty instance name is provided, the server automatically uses the port number as its instance name");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("FMQ INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_fmq_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_fmq_url");
    tt->descr = tdrpStrDup("URL for input FMQ data.");
    tt->help = tdrpStrDup("This server reads radar moments from a DsRadar FMQ. This is the URL of the input data.");
    tt->val_offset = (char *) &input_fmq_url - &_start_;
    tt->single_val.s = tdrpStrDup("fmqp:://localhost::fmq/spol");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("INPUT/OUTPUT FIELD NAMES");
    tt->comment_text = tdrpStrDup("These parameters specify the field names which match the fields expected by the CHILL SDB beam format. If the field does not exist in the input stream, it will be ignored. For fields which you know are not present you can set the strings to empty.");
    tt++;
    
    // Parameter 'DBZ_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("DBZ_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &DBZ_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'VEL_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("VEL_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &VEL_name - &_start_;
    tt->single_val.s = tdrpStrDup("VEL");
    tt++;
    
    // Parameter 'WIDTH_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("WIDTH_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &WIDTH_name - &_start_;
    tt->single_val.s = tdrpStrDup("WIDTH");
    tt++;
    
    // Parameter 'NCP_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("NCP_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &NCP_name - &_start_;
    tt->single_val.s = tdrpStrDup("NCP");
    tt++;
    
    // Parameter 'ZDR_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("ZDR_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &ZDR_name - &_start_;
    tt->single_val.s = tdrpStrDup("ZDR");
    tt++;
    
    // Parameter 'PHIDP_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("PHIDP_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &PHIDP_name - &_start_;
    tt->single_val.s = tdrpStrDup("PHIDP");
    tt++;
    
    // Parameter 'RHOHV_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("RHOHV_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &RHOHV_name - &_start_;
    tt->single_val.s = tdrpStrDup("RHOHV");
    tt++;
    
    // Parameter 'LDRH_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LDRH_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &LDRH_name - &_start_;
    tt->single_val.s = tdrpStrDup("LDRH");
    tt++;
    
    // Parameter 'LDRV_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LDRV_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &LDRV_name - &_start_;
    tt->single_val.s = tdrpStrDup("LDRV");
    tt++;
    
    // Parameter 'KDP_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("KDP_name");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &KDP_name - &_start_;
    tt->single_val.s = tdrpStrDup("KDP");
    tt++;
    
    // Parameter 'DBZc_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("DBZc_name");
    tt->descr = tdrpStrDup("DBZ corrected for attenuation, using KDP");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &DBZc_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZc");
    tt++;
    
    // Parameter 'ZDRc_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("ZDRc_name");
    tt->descr = tdrpStrDup("ZDR corrected for attenuation, using KDP");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &ZDRc_name - &_start_;
    tt->single_val.s = tdrpStrDup("ZDRc");
    tt++;
    
    // Parameter 'PHIDPf_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("PHIDPf_name");
    tt->descr = tdrpStrDup("PHIDP filtered and smoothed for computing KDP");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &PHIDPf_name - &_start_;
    tt->single_val.s = tdrpStrDup("PHIDPf");
    tt++;
    
    // Parameter 'AVG_H_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("AVG_H_MAG_name");
    tt->descr = tdrpStrDup("AVG H IQ magnitude");
    tt->help = tdrpStrDup("DSR field name for magnitude of average IQ, H channel");
    tt->val_offset = (char *) &AVG_H_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("AVG_H_MAG");
    tt++;
    
    // Parameter 'AVG_H_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("AVG_H_PHASE_name");
    tt->descr = tdrpStrDup("AVG H IQ phase");
    tt->help = tdrpStrDup("DSR field name for phase of average IQ, H channel");
    tt->val_offset = (char *) &AVG_H_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("AVG_H_PHASE");
    tt++;
    
    // Parameter 'AVG_V_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("AVG_V_MAG_name");
    tt->descr = tdrpStrDup("AVG V IQ magnitude");
    tt->help = tdrpStrDup("DSR field name for magnitude of average IQ, V channel");
    tt->val_offset = (char *) &AVG_V_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("AVG_V_MAG");
    tt++;
    
    // Parameter 'AVG_V_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("AVG_V_PHASE_name");
    tt->descr = tdrpStrDup("AVG V IQ phase");
    tt->help = tdrpStrDup("DSR field name for phase of average IQ, V channel");
    tt->val_offset = (char *) &AVG_V_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("AVG_V_PHASE");
    tt++;
    
    // Parameter 'LAG0_HC_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_HC_name");
    tt->descr = tdrpStrDup("Lag0 HC power");
    tt->help = tdrpStrDup("DSR field name for lag0 (power) H co-polar");
    tt->val_offset = (char *) &LAG0_HC_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_HC");
    tt++;
    
    // Parameter 'LAG0_VC_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_VC_name");
    tt->descr = tdrpStrDup("Lag0 VC power");
    tt->help = tdrpStrDup("DSR field name for lag0 (power) V co-polar");
    tt->val_offset = (char *) &LAG0_VC_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_VC");
    tt++;
    
    // Parameter 'LAG0_HX_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_HX_name");
    tt->descr = tdrpStrDup("Lag0 HX power");
    tt->help = tdrpStrDup("DSR field name for lag0 (power) H cross-polar");
    tt->val_offset = (char *) &LAG0_HX_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_HX");
    tt++;
    
    // Parameter 'LAG0_VX_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_VX_name");
    tt->descr = tdrpStrDup("Lag0 VX power");
    tt->help = tdrpStrDup("DSR field name for lag0 (power) V cross-polar");
    tt->val_offset = (char *) &LAG0_VX_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_VX");
    tt++;
    
    // Parameter 'LAG1_HC_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG1_HC_MAG_name");
    tt->descr = tdrpStrDup("Lag1 HC magnitude");
    tt->help = tdrpStrDup("DSR field name for lag1 H co-polar magnitude (dB)");
    tt->val_offset = (char *) &LAG1_HC_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG1_HC_MAG");
    tt++;
    
    // Parameter 'LAG1_HC_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG1_HC_PHASE_name");
    tt->descr = tdrpStrDup("Lag1 HC phase");
    tt->help = tdrpStrDup("DSR field name for lag1 H co-polar phase (deg)");
    tt->val_offset = (char *) &LAG1_HC_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG1_HC_PHASE");
    tt++;
    
    // Parameter 'LAG1_VC_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG1_VC_MAG_name");
    tt->descr = tdrpStrDup("Lag1 VC magnitude");
    tt->help = tdrpStrDup("DSR field name for lag1 V co-polar magnitude (dB)");
    tt->val_offset = (char *) &LAG1_VC_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG1_VC_MAG");
    tt++;
    
    // Parameter 'LAG1_VC_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG1_VC_PHASE_name");
    tt->descr = tdrpStrDup("Lag1 VC phase");
    tt->help = tdrpStrDup("DSR field name for lag1 V co-polar phase (deg)");
    tt->val_offset = (char *) &LAG1_VC_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG1_VC_PVASE");
    tt++;
    
    // Parameter 'LAG2_HC_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG2_HC_MAG_name");
    tt->descr = tdrpStrDup("Lag2 HC magnitude");
    tt->help = tdrpStrDup("DSR field name for lag2 H co-polar magnitude (dB)");
    tt->val_offset = (char *) &LAG2_HC_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG2_HC_MAG");
    tt++;
    
    // Parameter 'LAG2_HC_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG2_HC_PHASE_name");
    tt->descr = tdrpStrDup("Lag2 HC phase");
    tt->help = tdrpStrDup("DSR field name for lag2 H co-polar phase (deg)");
    tt->val_offset = (char *) &LAG2_HC_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG2_HC_PHASE");
    tt++;
    
    // Parameter 'LAG2_VC_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG2_VC_MAG_name");
    tt->descr = tdrpStrDup("Lag2 VC magnitude");
    tt->help = tdrpStrDup("DSR field name for lag2 V co-polar magnitude (dB)");
    tt->val_offset = (char *) &LAG2_VC_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG2_VC_MAG");
    tt++;
    
    // Parameter 'LAG2_VC_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG2_VC_PHASE_name");
    tt->descr = tdrpStrDup("Lag2 VC phase");
    tt->help = tdrpStrDup("DSR field name for lag2 V co-polar phase (deg)");
    tt->val_offset = (char *) &LAG2_VC_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG2_VC_PVASE");
    tt++;
    
    // Parameter 'LAG0_HV_MAG_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_HV_MAG_name");
    tt->descr = tdrpStrDup("Lag0 HV magnitude");
    tt->help = tdrpStrDup("DSR field name for lag0 HV magnitude (dB)");
    tt->val_offset = (char *) &LAG0_HV_MAG_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_HV_MAG");
    tt++;
    
    // Parameter 'LAG0_HV_PHASE_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("LAG0_HV_PHASE_name");
    tt->descr = tdrpStrDup("Lag0 HV phase");
    tt->help = tdrpStrDup("DSR field name for lag0 HV phase (deg)");
    tt->val_offset = (char *) &LAG0_HV_PHASE_name - &_start_;
    tt->single_val.s = tdrpStrDup("LAG0_HV_PHASE");
    tt++;
    
    // Parameter 'RHOHV_HCX_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("RHOHV_HCX_name");
    tt->descr = tdrpStrDup("RHOHV HC to VX");
    tt->help = tdrpStrDup("DSR field name for H co-pol to cross-pol correlation");
    tt->val_offset = (char *) &RHOHV_HCX_name - &_start_;
    tt->single_val.s = tdrpStrDup("RHOHV_HCX");
    tt++;
    
    // Parameter 'RHOHV_VCX_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("RHOHV_VCX_name");
    tt->descr = tdrpStrDup("RHOHV VC to HX");
    tt->help = tdrpStrDup("DSR field name for V co-pol to cross-pol correlation");
    tt->val_offset = (char *) &RHOHV_VCX_name - &_start_;
    tt->single_val.s = tdrpStrDup("RHOHV_VCX");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("POLARIZATION SETTING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'polarization_mode'
    // ctype is '_polarization_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("polarization_mode");
    tt->descr = tdrpStrDup("Polarization mode for output fields.");
    tt->help = tdrpStrDup("Downstream clients infer which fields are set from the polarization mode. H: H only. V: V only. VH: fast alternating mode. VHS: simulataneous mode.");
    tt->val_offset = (char *) &polarization_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("polarization_mode_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("POL_MODE_H");
      tt->enum_def.fields[0].val = POL_MODE_H;
      tt->enum_def.fields[1].name = tdrpStrDup("POL_MODE_V");
      tt->enum_def.fields[1].val = POL_MODE_V;
      tt->enum_def.fields[2].name = tdrpStrDup("POL_MODE_VH");
      tt->enum_def.fields[2].val = POL_MODE_VH;
      tt->enum_def.fields[3].name = tdrpStrDup("POL_MODE_VHS");
      tt->enum_def.fields[3].val = POL_MODE_VHS;
    tt->single_val.e = POL_MODE_VH;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("SERVER OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("port");
    tt->descr = tdrpStrDup("Port number.");
    tt->help = tdrpStrDup("The server listens on this port for client requests.");
    tt->val_offset = (char *) &port - &_start_;
    tt->single_val.i = 2111;
    tt++;
    
    // Parameter 'max_clients'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_clients");
    tt->descr = tdrpStrDup("Maximum number of clients");
    tt->help = tdrpStrDup("This is the maximum number of threads the application will produce to handle client requests.  If the maximum is reached, new clients will be ignored until the number of clients drops below this limit.");
    tt->val_offset = (char *) &max_clients - &_start_;
    tt->single_val.i = 32;
    tt++;
    
    // Parameter 'beam_wait_msecs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("beam_wait_msecs");
    tt->descr = tdrpStrDup("Wait between beams (msecs).");
    tt->help = tdrpStrDup("Optional wait between beams, in milliseconds. This can be useful when a server is trying to catch up with a data stream and is therefore flooding the client with data.");
    tt->val_offset = (char *) &beam_wait_msecs - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }