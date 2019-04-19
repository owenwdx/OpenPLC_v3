//-----------------------------------------------------------------------------
// Copyright 2015 Thiago Alves
// This file is part of the OpenPLC Software Stack.
//
// OpenPLC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OpenPLC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OpenPLC.  If not, see <http://www.gnu.org/licenses/>.
//------
//
// This file is responsible for gluing the variables from the IEC program to
// the OpenPLC memory pointers. It is automatically generated by the
// glue_generator program. PLEASE DON'T EDIT THIS FILE!
// Thiago Alves, May 2016
//-----------------------------------------------------------------------------

#include "iec_std_lib.h"

TIME __CURRENT_TIME;
extern unsigned long long common_ticktime__;

#ifndef OPLC_IEC_GLUE_VALUE_TYPE
#define OPLC_IEC_GLUE_VALUE_TYPE
enum IecGlueValueType {
	IECVT_BOOL,
	IECVT_BYTE,
	IECVT_SINT,
	IECVT_USINT,
	IECVT_INT,
	IECVT_UINT,
	IECVT_WORD,
	IECVT_DINT,
	IECVT_UDINT,
	IECVT_DWORD,
	IECVT_REAL,
	IECVT_LREAL,
	IECVT_LWORD,
	IECVT_LINT,
	IECVT_ULINT,
	IECVT_UNASSIGNED,
};
#endif // OPLC_IEC_GLUE_VALUE_TYPE

#ifndef OPLC_GLUE_VARIABLE
#define OPLC_GLUE_VARIABLE
/// Defines the mapping for a glued variable.
struct GlueVariable {
	/// The type of the glue variable.
	IecGlueValueType type;
	/// A pointer to the memory address for reading/writing the value.
	void* value;
};
#endif // OPLC_GLUE_VARIABLE


//Internal buffers for I/O and memory. These buffers are defined in the
//auto-generated glueVars.cpp file
#define BUFFER_SIZE		1024

//Booleans
IEC_BOOL *bool_input[BUFFER_SIZE][8];
IEC_BOOL *bool_output[BUFFER_SIZE][8];

//Bytes
IEC_BYTE *byte_input[BUFFER_SIZE];
IEC_BYTE *byte_output[BUFFER_SIZE];

//Analog I/O
IEC_UINT *int_input[BUFFER_SIZE];
IEC_UINT *int_output[BUFFER_SIZE];

//Memory
IEC_UINT *int_memory[BUFFER_SIZE];
IEC_DINT *dint_memory[BUFFER_SIZE];
IEC_LINT *lint_memory[BUFFER_SIZE];

#define __LOCATED_VAR(type, name, ...) type __##name;
#include "LOCATED_VARIABLES.h"
#undef __LOCATED_VAR
#define __LOCATED_VAR(type, name, ...) type* name = &__##name;
#include "LOCATED_VARIABLES.h"
#undef __LOCATED_VAR

void glueVars()
{
}

/// The size of the array of input variables
const std::uint16_t OPLCGLUE_INPUT_SIZE(0);
GlueVariable oplc_input_vars[] = {
	{ IECVT_UNASSIGNED, nullptr },
};

/// The size of the array of output variables
const std::uint16_t OPLCGLUE_OUTPUT_SIZE(0);
GlueVariable oplc_output_vars[] = {
	{ IECVT_UNASSIGNED, nullptr },
};

void updateTime()
{
	__CURRENT_TIME.tv_nsec += common_ticktime__;

	if (__CURRENT_TIME.tv_nsec >= 1000000000)
	{
		__CURRENT_TIME.tv_nsec -= 1000000000;
		__CURRENT_TIME.tv_sec += 1;
	}
}