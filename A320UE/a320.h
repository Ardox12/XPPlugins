/**
 * A320UE - X-Plane 11 Plugin
 *
 * A plugin for the FlightFactor A320 Ultimate that adds a couple of new
 * commands for operating the thrust levers more comfortably as well as a
 * bunch of other little workarounds and/or features.
 *
 * Copyright 2019 Torben K�nke.
 */
#ifndef _A320_H_
#define _A320_H_
/* FFA320 Interface */
#define Value_Type_Deleted              0
#define Value_Type_Object               1
#define Value_Type_sint8                2
#define Value_Type_uint8                3
#define Value_Type_sint16               4
#define Value_Type_uint16               5
#define Value_Type_sint32               6
#define Value_Type_uint32               7
#define Value_Type_float32              8
#define Value_Type_float64              9
#define Value_Type_String               10
#define Value_Type_Time                 11

#define Value_Flag_State            (1<<1) /* state parameter */
#define Value_Flag_Sync             (1<<2) /* force sync */
#define Value_Flag_Step             (1<<3) /* step parameter */
#define Value_Flag_External         (1<<4) /* external parameter */
#define Value_Flag_Config           (1<<5) /* config parameter */

#define Value_Unit_Object           (1<<0)
#define Value_Unit_Failure          (1<<1)
#define Value_Unit_Button           (1<<2)
#define Value_Unit_Ratio            (1<<3) /* floating ratio */
#define Value_Unit_State            (1<<4) /* sinteger state */
#define Value_Unit_Flags            (1<<5) /* uinteger flags */
#define Value_Unit_Ident            (1<<6) /* achar ident */
#define Value_Unit_Length           (1<<7) /* Meter */
#define Value_Unit_Speed            (1<<8) /* Meter/Second */
#define Value_Unit_Accel            (1<<9) /* Meter/Second^2 */
#define Value_Unit_Force            (1<<10) /* Newton */
#define Value_Unit_Weight           (1<<11) /* Kilogram */
#define Value_Unit_Angle            (1<<12) /* Degrees */
#define Value_Unit_AngularSpeed     (1<<13) /* Degrees/Second */
#define Value_Unit_AngularAccel     (1<<14) /* Degrees/Second^2 */
#define Value_Unit_Temperature      (1<<15) /* Kelvin */
#define Value_Unit_Pressure         (1<<16) /* Pascal */
#define Value_Unit_Flow             (1<<17) /* Kilogram/Second */
#define Value_Unit_Voltage          (1<<18) /* Volt */
#define Value_Unit_Frequency        (1<<19) /* Herz */
#define Value_Unit_Current          (1<<20) /* Amper */
#define Value_Unit_Power            (1<<21) /* Watt */
#define Value_Unit_Density          (1<<22) /* Kg/m3 */
#define Value_Unit_Volume           (1<<23) /* m3 */
#define Value_Unit_Conduction       (1<<24) /* 1/Resistance */
#define Value_Unit_Capacity         (1<<25) /* Amper/Second */
#define Value_Unit_Heat             (1<<26) /* Kelvin/(Kilogram/Second) */
#define Value_Unit_Position         (1<<27) /* Radians */
#define Value_Unit_Time             (1<<28) /* Seconds */
#define Value_Unit_TimeDelta        (1<<29) /* 1/10000000 of second */
#define Value_Unit_TimeStart        (1<<30) /* 1/10000000 of second */
#define Value_Unit_Label            (1<<31) /* ARINC 429 label */

typedef unsigned int(*SharedDataVersionProc)();
typedef void(*SharedDataUpdateProc)(double step, void *tag);
typedef void(*SharedDataAddUpdateProc)(SharedDataUpdateProc proc,
    void *tag);
typedef void(*SharedDataDelUpdateProc)(SharedDataUpdateProc proc,
    void *tag);
typedef unsigned int(*SharedValuesCountProc)();
typedef int(*SharedValueIdByIndexProc)(unsigned int index);
typedef int(*SharedValueIdByNameProc)(const char *name);
typedef const char *(*SharedValueNameProc)(int id);
typedef const char *(*SharedValueDescProc)(int id);
typedef unsigned int(*SharedValueTypeProc)(int id);
typedef unsigned int(*SharedValueFlagsProc)(int id);
typedef unsigned int(*SharedValueUnitsProc)(int id);
typedef int(*SharedValueParentProc)(int id);
typedef void(*SharedValueSetProc)(int id, const void *src);
typedef void(*SharedValueGetProc)(int id, void *dst);
typedef unsigned int(*SharedValueGetSizeProc)(int id);
typedef void(*SharedValueReaderProc)(void *dst, unsigned int size,
    void *tag);
typedef void(*SharedValueWriterProc)(const void *src,
    unsigned int size, void *tag);
typedef int(*SharedValueObjectLoadStateProc)(int id,
    SharedValueReaderProc src, void *tag);
typedef void(*SharedValueObjectSaveStateProc)(int id,
    SharedValueWriterProc dst, void *tag);
typedef int(*SharedValueObjectNewValueProc)(int id,
    const char *name, const char *desc, void *ptr, unsigned int type,
    unsigned int flags, unsigned int units);

#define XPLM_FF_SIGNATURE                   "FlightFactor.A320.ultimate"
#define XPLM_FF_MSG_GET_SHARED_INTERFACE    1001

typedef struct {
    /* to get actual dataset version */
    SharedDataVersionProc DataVersion;
    /* register an update callback called at each frame in sync with platform
       and aircraft values update, for using values functions below */
    SharedDataAddUpdateProc DataAddUpdate;
    /* remove a registred update callback */
    SharedDataDelUpdateProc DataDelUpdate;
    /* get count off all values (including deleted) */
    SharedValuesCountProc ValuesCount;
    /* get value id by it's index (0 up to ValuesCount), or -1 if not exists
       or removed */
    SharedValueIdByIndexProc ValueIdByIndex;
    /* get value id by it's name, or -1 if not exists or removed */
    SharedValueIdByNameProc ValueIdByName;
    /* get value name */
    SharedValueNameProc ValueName;
    /* get value description */
    SharedValueDescProc ValueDesc;
    /* get value type, one of Value_Type_ */
    SharedValueTypeProc ValueType;
    /* get value flags, OR Value_Flag_ */
    SharedValueFlagsProc ValueFlags;
    /* get value units, OR Value_Unit_ */
    SharedValueUnitsProc ValueUnits;
    /* get id of the parent object value */
    SharedValueParentProc ValueParent;
    /* set value */
    SharedValueSetProc ValueSet;
    /* get value */
    SharedValueGetProc ValueGet;
    /* get actual size of the value data (for strings) */
    SharedValueGetSizeProc ValueGetSize;
    /* deserialize object state */
    SharedValueObjectLoadStateProc ValueObjectLoadState;
    /* serialize object state */
    SharedValueObjectSaveStateProc ValueObjectSaveState;
    /* add a new value */
    SharedValueObjectNewValueProc ValueObjectNewValue;
} SharedValuesInterface;
#endif /* _A320_H_ */
