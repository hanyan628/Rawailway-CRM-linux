#ifndef CRM_VAR_H_INCLUDED
#define CRM_VAR_H_INCLUDED

enum MODULE_RIGHTS{
    maskWelcomeRecord   = ( 1<<0 ),
    maskDayAccount      = ( 1<<1 ),
    maskMonthAccount    = ( 1<<2 ),
    maskTrainsDef       = ( 1<<3 ),
    maskOperatorDef     = ( 1<<4 ),
    maskImageDef        = ( 1<<5 ),
    maskGuestsDef       = ( 1<<6 ),
    maskRecordModify    = ( 1<<7 ),
    maskParameterDef    = ( 1<<8 ),
    maskNoneDefine      = ( 1<<9 )
};


#endif // CRM_VAR_H_INCLUDED
