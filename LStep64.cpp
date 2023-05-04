
#include	"stdafx.h"
#include	"LStep64.h"


/////////////////////////////////////////////////////////////////////////////
// Klasse CLStep64


// Konstruktor: Versucht DLL und alle Zeiger auf Funktionsaufrufe zu laden
CLStep64::CLStep64()
{
        m_DLLResultat=0;		// DLL-Zugriff ok

        // Zeiger auf alle Funktionen Nullsetzen
        m_pConnect=NULL;
        m_pConnectSimple=NULL;
        m_pConnectSimpleW=NULL;
        m_pConnectEx=NULL;
        m_pConnectExW=NULL;
        m_pDisconnect=NULL;
        m_pLoadConfig=NULL;
        m_pLoadConfigW=NULL;
        m_pSaveConfig=NULL;
        m_pSaveConfigW=NULL;
        m_pMoveAbs=NULL;
        m_pMoveRel=NULL;
        m_pCalibrate=NULL;
        m_pRMeasure=NULL;
        m_pSetPitch=NULL;
        m_pSetPos=NULL;
        m_pSetActiveAxes=NULL;
        m_pSetVel=NULL;
        m_pSetAccel=NULL;
        m_pSetRoomAccelJerk=NULL;
        m_pGetRoomAccelJerk=NULL;
        m_pSetRoomDecelJerk=NULL;
        m_pGetRoomDecelJerk=NULL;
        m_pSetRoomStopJerk=NULL;
        m_pGetRoomStopJerk=NULL;
        m_pSetRoomAccel=NULL;
        m_pGetRoomAccel=NULL;
        m_pSetRoomDecel=NULL;
        m_pGetRoomDecel=NULL;
        m_pSetRoomStopDecel=NULL;
        m_pGetRoomStopDecel=NULL;
        m_pSetRoomVel=NULL;
        m_pGetRoomVel=NULL;
        m_pSetReduction=NULL;
        m_pSetDelay=NULL;
        m_pSetSwitchPolarity=NULL;
        m_pSetSwitchActive=NULL;
        m_pSetJoystickOn=NULL;
        m_pSetJoystickOff=NULL;
        m_pSoftwareReset=NULL;
        m_pSetDigitalOutput=NULL;
        m_pGetDigitalInputs=NULL;
        m_pSetAnalogOutput=NULL;
        m_pGetAnalogInput=NULL;
        m_pSetLimit=NULL;
        m_pSetLimitControl=NULL;
        m_pGetPos=NULL;
        m_pGetStatus=NULL;
        m_pGetStatusW=NULL;
        m_pGetEncoderMask=NULL;
        m_pStopAxes=NULL;
        m_pSetAbortFlag=NULL;
        m_pMoveRelSingleAxis=NULL;
        m_pMoveAbsSingleAxis=NULL;
        m_pMoveSequence=NULL;
        m_pSetControlPars=NULL;
        m_pSetMotorCurrent=NULL;
        m_pSetMotorAutoKommCurrent=NULL;
        m_pGetMotorAutoKommCurrent=NULL;
        m_pSetMotorpeakCurrent=NULL;
        m_pGetMotorpeakCurrent=NULL;
        m_pSetMotorpeakCurrentTime=NULL;
        m_pGetMotorpeakCurrentTime=NULL;
        m_pSetMotorIITCheck=NULL;
        m_pGetMotorIITCheck=NULL;
        m_pSetVelSingleAxis=NULL;
        m_pSetAccelSingleAxis=NULL;
        m_pCalibrateEx=NULL;
        m_pRMeasureEx=NULL;
        m_pSetShowProt=NULL;
        m_pGetAnalogInputs2=NULL;
        m_pSendString=NULL;
        m_pSendStringW=NULL;
        m_pSetSpeedPoti=NULL;
        m_pSetTVRMode=NULL;
        m_pSetAutoStatus=NULL;
        m_pGetStatusAxis=NULL;
        m_pGetStatusAxisW=NULL;
        m_pSetDigIO_Off=NULL;
        m_pSetDigIO_Polarity=NULL;
        m_pSetDigIO_EmergencyStop=NULL;
        m_pSetDigIO_Distance=NULL;
        m_pSetDimensions=NULL;
        m_pMoveRelShort=NULL;
        m_pSetEncoderPeriod=NULL;
        m_pSetJoystickDir=NULL;
        m_pSetEncoderMask=NULL;
        m_pSetGear=NULL;
        m_pSetHandWheelOn=NULL;
        m_pSetHandWheelOff=NULL;
        m_pSetFactorTVR=NULL;
        m_pSetController=NULL;
        m_pSetControllerCall=NULL;
        m_pSetControllerSteps=NULL;
        m_pSetControllerFactor=NULL;
        m_pSetControllerTWDelay=NULL;
        m_pSetEncoderRefSignal=NULL;
        m_pSetEncoderPosition=NULL;
        m_pGetVersionStr=NULL;
        m_pGetVersionStrW=NULL;
        m_pGetError=NULL;
        m_pGetPosSingleAxis=NULL;
        m_pSetDistance=NULL;
        m_pGetPosEx=NULL;
        m_pSetShowCmdList=NULL;
        m_pSetWriteLogText=NULL;
        m_pSetControllerTimeout=NULL;
        m_pSetEncoderActive=NULL;
        m_pGetSnapshotCount=NULL;
        m_pGetSnapshotPos=NULL;
        m_pSetCorrTblOff=NULL;
        m_pSetCorrTblOn=NULL;
        m_pSetCorrTblOnW=NULL;
        m_pSetFactorMode=NULL;
        m_pSetSnapshot=NULL;
        m_pSetSnapshotPar=NULL;
        m_pSetTrigger=NULL;
        m_pSetTrigger_=NULL;
        m_pSetTriggerPar=NULL;
        m_pSetTrigger_TwoPar=NULL;
        m_pSetTriggerSource=NULL;
        m_pGetTriggerSource=NULL;
        m_pSetTrigger_TwoSource=NULL;
        m_pGetTrigger_TwoSource=NULL;
        m_pSetTriggerHysterese=NULL;
        m_pGetTriggerHysterese=NULL;
        m_pSetTrigger_TwoHysterese=NULL;
        m_pGetTrigger_TwoHysterese=NULL;
        m_pSetTriggerPLength=NULL;
        m_pGetTriggerPLength=NULL;
        m_pSetTrigger_TwoPLength=NULL;
        m_pGetTrigger_TwoPLength=NULL;
        m_pSetTriggerPulsCount=NULL;
        m_pGetTriggerPulsCount=NULL;
        m_pSetTrigger_TwoPulsCount=NULL;
        m_pGetTrigger_TwoPulsCount=NULL;
        m_pSetConfigurated=NULL;
        m_pGetConfigurated=NULL;
        m_pSetStopMode=NULL;
        m_pGetStopMode=NULL;
        m_pSetStopSwitchOffDelay =NULL;
        m_pGetStopSwitchOffDelay =NULL;
        m_pSetLanguage=NULL;
        m_pSetLanguageW=NULL;
        m_pGetSwitches=NULL;
        m_pGetSerialNr=NULL;
        m_pGetSerialNrW=NULL;
        m_pSetCSOffset=NULL;
        m_pGetCSOffset=NULL;
        m_pSetCalibRMOffsetSWAct=NULL;
        m_pGetCalibRMOffsetSWAct=NULL;
        m_pMoveAbsV=NULL;
        m_pMoveAbsVW=NULL;
        m_pMoveRelV=NULL;
        m_pMoveRelVW=NULL;
        m_pGetDeviationValue=NULL;
        m_pSetAutoKomm=NULL;
        m_pSetAutoKommW=NULL;
        m_pGetAutoKomm=NULL;
        m_pGetAutoKommResult=NULL;
        m_pSetTablePos=NULL;
        m_pGetTablePos=NULL;
        m_pSetIndexTableDivider=NULL;
        m_pGetIndexTableDivider=NULL;
        m_pMoveTablePosAbs=NULL;
        m_pMoveTablePosAbsW=NULL;
        m_pMoveTablePosRel=NULL;
        m_pMoveTablePosRelW=NULL;
        m_pMoveIndexTable=NULL;
        m_pMoveIndexTableW=NULL;
        m_pSetSpeedEnable=NULL;
        m_pGetSpeedEnable=NULL;
        m_pSetSpeed=NULL;
        m_pGetSpeed=NULL;
        m_pSetMixedMoveAxisMode=NULL;
        m_pGetMixedMoveAxisMode=NULL;
        m_pMixedMoveAbs=NULL;
        m_pMixedMoveAbsW=NULL;
        m_pMixedMoveRel=NULL;
        m_pMixedMoveRelW=NULL;
        m_pSetMixedMovePos=NULL;
        m_pGetMixedMovePos=NULL;
        m_pSetMixedMoveAmpl=NULL;
        m_pGetMixedMoveAmpl=NULL;
        m_pSetMoveSeqStatusPos=NULL;
        m_pGetMoveSeqStatusPos=NULL;
        m_pSetMoveSeqStatus=NULL;
        m_pSetMoveSeqStatusW=NULL;
        m_pGetMoveSeqStatus=NULL;
        m_pSetMoveSeqVar=NULL;
        m_pGetMoveSeqVar=NULL;
        m_pSetCalibOffset=NULL;
        m_pSetRMOffset=NULL;
        m_pGetSnapshotPosArray=NULL;
        m_pSetAxisDirection=NULL;
        m_pSetCalibrateDir=NULL;
        m_pLStepSave=NULL;
        m_pSetBPZ=NULL;
        m_pSetBPZTrackballFactor=NULL;
        m_pSetBPZTrackballBackLash=NULL;
        m_pSetBPZJoyspeed=NULL;
        m_pSetJoystickWindow=NULL;
        m_pSetCurrentDelay=NULL;
        m_pMoveEx=NULL;
        m_pWaitForAxisStop=NULL;
        m_pSendStringPosCmd=NULL;
        m_pSendStringPosCmdW=NULL;
        m_pSetDigitalOutputs=NULL;
        m_pSetWriteLogTextFN=NULL;
        m_pSetWriteLogTextFNW=NULL;
        m_pEnableGlobalLogging=NULL;
        m_pEnableGuiLogging=NULL;
        m_pSetDigitalOutputsE=NULL;
        m_pSetDigOutLinktoSignal=NULL;
        m_pGetDigOutLinktoSignal=NULL;
        m_pSetMonitoringVelFilter=NULL;
        m_pGetMonitoringVelFilter=NULL;
        m_pSetHaltSignalVel=NULL;
        m_pGetHaltSignalVel=NULL;
        m_pSetThresholdSignalVel=NULL;
        m_pGetThresholdSignalVel=NULL;
        m_pSetInvertDigOutSignal=NULL;
        m_pGetInvertDigOutSignal=NULL;
        m_pGetDigitalInputsE=NULL;
        m_pEnableCommandRetry=NULL;
        m_pSetXYAxisComp=NULL;
        m_pGetVersionStrDet=NULL;
        m_pGetVersionStrDetW=NULL;
        m_pGetAPIVersion=NULL;
        m_pGetAPIVersionW=NULL;
        m_pSetCommandTimeout=NULL;
        m_pSetExtValue=NULL;
        m_pFlushBuffer=NULL;
        m_pSetProcessMessagesProc=NULL;
        m_pGetEEPRomValue=NULL;
        m_pSetEEPRomValue=NULL;
        m_pGetXYAxisComp=NULL;
        m_pGetDimensions=NULL;
        m_pGetPitch=NULL;
        m_pGetGear=NULL;
        m_pGetVel=NULL;
        m_pGetAccel=NULL;
        m_pSetVelFac=NULL;
        m_pSetVelFacSingleAxis=NULL;
        m_pGetVelFac=NULL;
        m_pGetSpeedPoti=NULL;
        m_pGetMotorCurrent=NULL;
        m_pGetReduction=NULL;
        m_pGetCurrentDelay=NULL;
        m_pSetOutFuncLev=NULL;
        m_pGetOutFuncLev=NULL;
        m_pGetActiveAxes=NULL;
        m_pGetAxisDirection=NULL;
        m_pGetCalibOffset=NULL;
        m_pGetRMOffset=NULL;
        m_pGetCalibrateDir=NULL;
        m_pSetCalibBackSpeed=NULL;
        m_pGetCalibBackSpeed=NULL;
        m_pSetRefSpeed=NULL;
        m_pGetRefSpeed=NULL;
        m_pSetPowerAmplifier=NULL;
        m_pGetPowerAmplifier=NULL;
        m_pValidConfig=NULL;
        m_pValidPar=NULL;
        m_pSetEqepConfig=NULL;
        m_pGetEqepConfig=NULL;
        m_pSetTTLOutConfig=NULL;
        m_pGetTTLOutConfig=NULL;
        m_pSetPoscon=NULL;
        m_pGetPoscon=NULL;
        m_pSetManModePreselection=NULL;
        m_pGetManModePreselection=NULL;
        m_pGetManModeLinktoAxisX=NULL;
        m_pGetManModeLinktoAxisY=NULL;
        m_pGetManModeLinktoAxisZ=NULL;
        m_pGetManModeLinktoAxisA=NULL;
        m_pSetJoyRedCur=NULL;
        m_pSetAnaOutPreset=NULL;
        m_pGetAnaOutPreset=NULL;
        m_pGetJoyRedCur=NULL;
        m_pSetJoytoAxis=NULL;
        m_pGetJoytoAxis=NULL;
        m_pSetTipp=NULL;
        m_pGetTipp=NULL;
        m_pSetTippEnable=NULL;
        m_pGetTippEnable=NULL;
        m_pSetTippRedCur=NULL;
        m_pGetTippRedCur=NULL;
        m_pSetTippVel=NULL;
        m_pGetTippVel=NULL;
        m_pSetTippDir=NULL;
        m_pGetTippDir=NULL;
        m_pSetModulo=NULL;
        m_pGetModulo=NULL;
        m_pSetModuloMode=NULL;
        m_pGetModuloMode=NULL;
        m_pSetEncDir=NULL;
        m_pGetEncDir=NULL;
        m_pSetEncPolePairs=NULL;
        m_pGetEncPolePairs=NULL;
        m_pSetEnctoAxis=NULL;
        m_pGetEnctoAxis=NULL;
        m_pSetEncType=NULL;
        m_pGetEncType=NULL;
        m_pSetMotortempSensor=NULL;
        m_pGetMotortempSensor=NULL;
        m_pSetMotortempSensormin=NULL;
        m_pGetMotortempSensormin=NULL;
        m_pSetMotortempSensormax=NULL;
        m_pGetMotortempSensormax=NULL;
        m_pGetMotortempSensorValue=NULL;
        m_pSetKommMode=NULL;
        m_pGetKommMode=NULL;
        m_pSetKommEncDir=NULL;
        m_pGetKommEncDir=NULL;
        m_pSetKommEncPolePairs=NULL;
        m_pGetKommEncPolePairs=NULL;
        m_pSetKommEnctoAxis=NULL;
        m_pGetKommEnctoAxis=NULL;
        m_pSetKommEncType=NULL;
        m_pGetKommEncType=NULL;
        m_pSetMotorPolePairs=NULL;
        m_pGetMotorPolePairs=NULL;
        m_pSetMotorPolePairRes=NULL;
        m_pGetMotorPolePairRes=NULL;
        m_pSetMotorPoleScale=NULL;
        m_pGetMotorPoleScale=NULL;
        m_pGetSysStat=NULL;
        m_pGetSysStatusW=NULL;
        m_pGetSysStatus=NULL;
        m_pGetStopStatus=NULL;
        m_pQuit=NULL;
        m_pSetMotorBrakeSwitchOnDelay=NULL;
        m_pGetMotorBrakeSwitchOnDelay=NULL;
        m_pSetMotorBrakeSwitchOffDelay=NULL;
        m_pGetMotorBrakeSwitchOffDelay=NULL;
        m_pSetMotorAutoKommDelay=NULL;
        m_pGetMotorAutoKommDelay=NULL;
        m_pSetMotorAutoKommSpeedScale=NULL;
        m_pGetMotorAutoKommSpeedScale=NULL;
        m_pSetMotorForceConstant=NULL;
        m_pGetMotorForceConstant=NULL;
        m_pSetMotorLoad=NULL;
        m_pGetMotorLoad=NULL;
        m_pSetMotorMomentConstant=NULL;
        m_pGetMotorMomentConstant=NULL;
        m_pSetMotorMomentOfInertia=NULL;
        m_pGetMotorMomentOfInertia=NULL;
        m_pSetPosConKP=NULL;
        m_pGetPosConKP=NULL;
        m_pSetPosConAdaptiveKP=NULL;
        m_pGetPosConAdaptiveKP=NULL;
        m_pSetPosConKI=NULL;
        m_pGetPosConKI=NULL;
        m_pSetPosConAdaptiveKI=NULL;
        m_pGetPosConAdaptiveKI=NULL;
        m_pSetPosConOutPass=NULL;
        m_pGetPosConOutPass=NULL;
        m_pSetPosConAdaptiveOutPass=NULL;
        m_pGetPosConAdaptiveOutPass=NULL;
        m_pSetPosConEnable=NULL;
        m_pGetPosConEnable=NULL;
        m_pSetSpeedConKP=NULL;
        m_pGetSpeedConKP=NULL;
        m_pSetSpeedConKI=NULL;
        m_pGetSpeedConKI=NULL;
        m_pSetSpeedConKD=NULL;
        m_pGetSpeedConKD=NULL;
        m_pSetSpeedConOutPass=NULL;
        m_pGetSpeedConOutPass=NULL;
        m_pSetPosConNominalSpeed=NULL;
        m_pGetPosConNominalSpeed=NULL;
        m_pSetPosConAdaptiveSpeed=NULL;
        m_pGetPosConAdaptiveSpeed=NULL;
        m_pSetActSpeedFilterConst=NULL;
        m_pGetActSpeedFilterConst=NULL;
        m_pSetSpeedFeedForward=NULL;
        m_pGetSpeedFeedForward=NULL;
        m_pSetActAccelFilterConst=NULL;
        m_pGetActAccelFilterConst=NULL;
        m_pSetAccelFeedForward=NULL;
        m_pGetAccelFeedForward=NULL;
        m_pSetAccelFeedForwardOutPass=NULL;
        m_pGetAccelFeedForwardOutPass=NULL;
        m_pSetPosMode=NULL;
        m_pGetPosMode=NULL;
        m_pGetSpeedConTN=NULL;
        m_pGetPowerAmplifierStatus=NULL;
        m_pGetPTemp=NULL;
        m_pSetSysSampleRate=NULL;
        m_pGetSysSampleRate=NULL;
        m_pSetAxisMap=NULL;
        m_pGetAxisMap=NULL;
        m_pSetBaud=NULL;
        m_pGetBaud=NULL;
        m_pSetTrigger_Two=NULL;
        m_pGetTrigger_Two=NULL;
        m_pSetTriggerDim=NULL;
        m_pGetTriggerDim=NULL;
        m_pSetTrigger_TwoDim=NULL;
        m_pGetTrigger_TwoDim=NULL;
        m_pSetPosWindowRange=NULL;
        m_pGetPosWindowRange=NULL;
        m_pSetPosWindowTime=NULL;
        m_pGetPosWindowTime=NULL;
        m_pSetPosWindowTimeout=NULL;
        m_pGetPosWindowTimeout=NULL;
        m_pSetPosWindowCheck=NULL;
        m_pGetPosWindowCheck=NULL;
        m_pSetDeviationRange=NULL;
        m_pGetDeviationRange=NULL;
        m_pSetDeviationTime=NULL;
        m_pGetDeviationTime=NULL;
        m_pSetDeviationCheck=NULL;
        m_pGetDeviationCheck=NULL;
        m_pSetHalt=NULL;
        m_pSetMotorTablePatch=NULL;
        m_pGetMotorTablePatch=NULL;
        m_pSetJoystickFilter=NULL;
        m_pGetJoystickFilter=NULL;
        m_pSetStopPolarity=NULL;
        m_pGetStopPolarity=NULL;
        m_pSetVLevel=NULL;
        m_pGetVLevel=NULL;
        m_pSetStopAccel=NULL;
        m_pGetStopAccel=NULL;
        m_pGetVersionStrInfo=NULL;
        m_pGetVersionStrInfoW=NULL;
        m_pGetStatusLimit=NULL;
        m_pGetStatusLimitW=NULL;
        m_pGetSecurityErr=NULL;
        m_pGetSecurityStatus=NULL;
        m_pGetDelay=NULL;
        m_pGetDistance=NULL;
        m_pClearPos=NULL;
        m_pSetDigJoySpeed=NULL;
        m_pGetDigJoySpeed=NULL;
        m_pGetJoystickDir=NULL;
        m_pGetJoystick=NULL;
        m_pGetJoystickWindow=NULL;
        m_pGetHandWheel=NULL;
        m_pGetBPZ=NULL;
        m_pGetBPZTrackballFactor=NULL;
        m_pGetBPZTrackballBackLash=NULL;
        m_pGetBPZJoyspeed=NULL;
        m_pGetLimitControl=NULL;
        m_pSetAutoLimitAfterCalibRM=NULL;
        m_pGetAutoLimitAfterCalibRM=NULL;
        m_pGetSwitchPolarity=NULL;
        m_pGetSwitchActive=NULL;
        m_pGetTVRMode=NULL;
        m_pGetFactorTVR=NULL;
        m_pSetTVROutMode=NULL;
        m_pGetTVROutMode=NULL;
        m_pSetTVROutResolution=NULL;
        m_pGetTVROutResolution=NULL;
        m_pSetTVROutPitch=NULL;
        m_pGetTVROutPitch=NULL;
        m_pSetVelTVRO=NULL;
        m_pGetVelTVRO=NULL;
        m_pSetAccelTVRO=NULL;
        m_pGetAccelTVRO=NULL;
        m_pSetVelSingleAxisTVRO=NULL;
        m_pSetAccelSingleAxisTVRO=NULL;
        m_pSetPosTVRO=NULL;
        m_pGetPosTVRO=NULL;
        m_pMoveAbsTVRO=NULL;
        m_pMoveRelTVRO=NULL;
        m_pMoveRelTVROSingleAxis=NULL;
        m_pMoveAbsTVROSingleAxis=NULL;
        m_pGetStatusTVRO=NULL;
        m_pGetStatusTVROW=NULL;
        m_pSetTargetWindow=NULL;
        m_pGetTargetWindow=NULL;
        m_pGetEncoderPeriod=NULL;
        m_pGetEncoderRefSignal=NULL;
        m_pGetEncoderPosition=NULL;
        m_pGetEncoderActive=NULL;
        m_pGetController=NULL;
        m_pGetControllerCall=NULL;
        m_pGetControllerSteps=NULL;
        m_pGetControllerFactor=NULL;
        m_pGetControllerTWDelay=NULL;
        m_pGetControllerTimeout=NULL;
        m_pSetCtrFastMoveOn=NULL;
        m_pSetCtrFastMoveOff=NULL;
        m_pGetCtrFastMove=NULL;
        m_pClearCtrFastMoveCounter=NULL;
        m_pGetCtrFastMoveCounter=NULL;
        m_pClearEncoder=NULL;
        m_pGetEncoder=NULL;
        m_pGetTrigger=NULL;
        m_pGetTrigger_=NULL;
        m_pGetTriggerPar=NULL;
        m_pGetTrigger_TwoPar=NULL;
        m_pSetTriggerCount=NULL;
        m_pGetTriggerCount=NULL;
        m_pSetTrigCount=NULL;
        m_pGetTrigCount=NULL;
        m_pSetTrigger_TwoCount=NULL;
        m_pGetTrigger_TwoCount=NULL;
        m_pSetSnapShotSource=NULL;
        m_pGetSnapShotSource=NULL;
        m_pSetTVRInPulse=NULL;
        m_pGetSnapshot=NULL;
        m_pSetSnapshotFilter=NULL;
        m_pGetSnapshotFilter=NULL;
        m_pGetSnapshotPar=NULL;
        m_pGetLimit=NULL;
        m_pJoyChangeAxis=NULL;
        m_pGetJoyChangeAxis=NULL;
        m_pSetDigJoyOff=NULL;
        m_pSetInputTrigMove=NULL;
        m_pGetInputTrigMove=NULL;
        m_pSetLimitControlMode=NULL;
        m_pGetLimitControlMode=NULL;
        m_pInitialize=NULL;
        m_pInitializeW=NULL;
        m_pSetAccelJerk=NULL;
        m_pSetDecelJerk=NULL;
        m_pSetCalibRMJerk=NULL;
        m_pSetJoyVel=NULL;
        m_pGetJoyVel=NULL;
        m_pSetJoyOutPass=NULL;
        m_pGetJoyOutPass=NULL;
        m_pSetTippOutPass=NULL;
        m_pGetTippOutPass=NULL;
        m_pSetMotorBrakeDigOut=NULL;
        m_pGetMotorBrakeDigOut=NULL;
        m_pGetMotorBrakeOut=NULL;
        m_pSetTrackBall=NULL;
        m_pGetTrackBall=NULL;
        m_pSetTrackBallVel=NULL;
        m_pGetTrackBallVel=NULL;
        m_pSetTrackBallEnable=NULL;
        m_pGetTrackBallEnable=NULL;
        m_pSetTrackBallRedCur=NULL;
        m_pGetTrackBallRedCur=NULL;
        m_pSetTrackBallDir=NULL;
        m_pGetTrackBallDir=NULL;
        m_pSetTrackBallToAxis=NULL;
        m_pGetTrackBallToAxis=NULL;
        m_pSetTrackBallOutPass=NULL;
        m_pGetTrackBallOutPass=NULL;
        m_pSetDigInStatus=NULL;
        m_pSetDigInStatusW=NULL;
        m_pGetDigInStatus=NULL;
        m_pSetDigInExtStatus=NULL;
        m_pSetDigInExtStatusW=NULL;
        m_pGetDigInExtStatus=NULL;
        m_pSetTTLDigOut=NULL;
        m_pGetTTLDigOut=NULL;
        m_pGetTTLDigIn=NULL;
        m_pSetTVR=NULL;
        m_pGetTVR=NULL;
        m_pSetTVRToAxis=NULL;
        m_pGetTVRToAxis=NULL;
        m_pSetDeceleration=NULL;
        m_pGetDeceleration=NULL;
        m_pSetDecelSingleAxis=NULL;
        m_pConfigMaxAxes=NULL;
        m_pSetMotorBrake=NULL;
        m_pGetMotorBrake=NULL;
        m_pSetJoystickAxes=NULL;
        m_pGetJoystickAxes=NULL;
        m_pSetJoyVelSkal=NULL;
        m_pGetJoyVelSkal=NULL;
        m_pSetMaxUserCurrent=NULL;
        m_pGetMaxUserCurrent=NULL;
        m_pSetStopDecel=NULL;
        m_pGetStopDecel=NULL;
        m_pSetMotorMaxVel=NULL;
        m_pGetMotorMaxVel=NULL;
        m_pSetMotorStandForce=NULL;
        m_pGetMotorStandForce=NULL;
        m_pSetMotorStandMoment=NULL;
        m_pGetMotorStandMoment=NULL;
        m_pSetMotorFieldDir=NULL;
        m_pGetMotorFieldDir=NULL;
        m_pSetMotorType=NULL;
        m_pGetMotorType=NULL;
        m_pSetOsziCallBackFct=NULL;
        m_pTranslateErrMsg=NULL;
        m_pSetCalibRMAccel=NULL;
        m_pGetCalibRMAccel=NULL;
        m_pGetCalibRMJerk=NULL;
        m_pSetCalibRMVel=NULL;
        m_pGetCalibRMVel=NULL;
        m_pSetCalibRMBackSpeed=NULL;
        m_pGetCalibRMBackSpeed=NULL;
        m_pGetAccelJerk=NULL;
        m_pGetDecelJerk=NULL;
        m_pSetGearDenominator=NULL;
        m_pGetGearDenominator=NULL;
        m_pSetGearNumerator=NULL;
        m_pGetGearNumerator=NULL;
        m_pSetStopDecelJerk=NULL;
        m_pGetStopDecelJerk=NULL;
        m_pSetSwChange=NULL;
        m_pGetSwChange=NULL;
        m_pSetExtCallBackFct=NULL;
        m_pCreateLSID=NULL;
        m_pFreeLSID=NULL;

        if ((m_LStep4=::LoadLibrary(_T("LStep64.DLL")))==0)
        {
                m_DLLResultat=-1; // DLL konnte nicht geladen werden
        }
        else
        {
                // Zeiger auf jede Methode der Dll laden und prüfen

                VERIFY(m_pConnect= (PConnect) GetProcAddress(m_LStep4,"LSX_Connect"));
                if (!m_pConnect) m_DLLResultat=-2;

                VERIFY(m_pConnectSimple= (PConnectSimple) GetProcAddress(m_LStep4,"LSX_ConnectSimple"));
                if (!m_pConnectSimple) m_DLLResultat=-2;

                VERIFY(m_pConnectSimpleW= (PConnectSimpleW) GetProcAddress(m_LStep4,"LSX_ConnectSimpleW"));
                if (!m_pConnectSimpleW) m_DLLResultat=-2;

                VERIFY(m_pConnectEx= (PConnectEx) GetProcAddress(m_LStep4,"LSX_ConnectEx"));
                if (!m_pConnectEx) m_DLLResultat=-2;

                VERIFY(m_pConnectExW= (PConnectExW) GetProcAddress(m_LStep4,"LSX_ConnectExW"));
                if (!m_pConnectExW) m_DLLResultat=-2;

                VERIFY(m_pDisconnect= (PDisconnect) GetProcAddress(m_LStep4,"LSX_Disconnect"));
                if (!m_pDisconnect) m_DLLResultat=-2;

                VERIFY(m_pLoadConfig= (PLoadConfig) GetProcAddress(m_LStep4,"LSX_LoadConfig"));
                if (!m_pLoadConfig) m_DLLResultat=-2;

                VERIFY(m_pLoadConfigW= (PLoadConfigW) GetProcAddress(m_LStep4,"LSX_LoadConfigW"));
                if (!m_pLoadConfigW) m_DLLResultat=-2;

                VERIFY(m_pSaveConfig= (PSaveConfig) GetProcAddress(m_LStep4,"LSX_SaveConfig"));
                if (!m_pSaveConfig) m_DLLResultat=-2;

                VERIFY(m_pSaveConfigW= (PSaveConfigW) GetProcAddress(m_LStep4,"LSX_SaveConfigW"));
                if (!m_pSaveConfigW) m_DLLResultat=-2;

                VERIFY(m_pMoveAbs= (PMoveAbs) GetProcAddress(m_LStep4,"LSX_MoveAbs"));
                if (!m_pMoveAbs) m_DLLResultat=-2;

                VERIFY(m_pMoveRel= (PMoveRel) GetProcAddress(m_LStep4,"LSX_MoveRel"));
                if (!m_pMoveRel) m_DLLResultat=-2;

                VERIFY(m_pCalibrate= (PCalibrate) GetProcAddress(m_LStep4,"LSX_Calibrate"));
                if (!m_pCalibrate) m_DLLResultat=-2;

                VERIFY(m_pRMeasure= (PRMeasure) GetProcAddress(m_LStep4,"LSX_RMeasure"));
                if (!m_pRMeasure) m_DLLResultat=-2;

                VERIFY(m_pSetPitch= (PSetPitch) GetProcAddress(m_LStep4,"LSX_SetPitch"));
                if (!m_pSetPitch) m_DLLResultat=-2;

                VERIFY(m_pSetPos= (PSetPos) GetProcAddress(m_LStep4,"LSX_SetPos"));
                if (!m_pSetPos) m_DLLResultat=-2;

                VERIFY(m_pSetActiveAxes= (PSetActiveAxes) GetProcAddress(m_LStep4,"LSX_SetActiveAxes"));
                if (!m_pSetActiveAxes) m_DLLResultat=-2;

                VERIFY(m_pSetVel= (PSetVel) GetProcAddress(m_LStep4,"LSX_SetVel"));
                if (!m_pSetVel) m_DLLResultat=-2;

                VERIFY(m_pSetAccel= (PSetAccel) GetProcAddress(m_LStep4,"LSX_SetAccel"));
                if (!m_pSetAccel) m_DLLResultat=-2;

                VERIFY(m_pSetRoomAccelJerk= (PSetRoomAccelJerk) GetProcAddress(m_LStep4,"LSX_SetRoomAccelJerk"));
                if (!m_pSetRoomAccelJerk) m_DLLResultat=-2;

                VERIFY(m_pGetRoomAccelJerk= (PGetRoomAccelJerk) GetProcAddress(m_LStep4,"LSX_GetRoomAccelJerk"));
                if (!m_pGetRoomAccelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetRoomDecelJerk= (PSetRoomDecelJerk) GetProcAddress(m_LStep4,"LSX_SetRoomDecelJerk"));
                if (!m_pSetRoomDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pGetRoomDecelJerk= (PGetRoomDecelJerk) GetProcAddress(m_LStep4,"LSX_GetRoomDecelJerk"));
                if (!m_pGetRoomDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetRoomStopJerk= (PSetRoomStopJerk) GetProcAddress(m_LStep4,"LSX_SetRoomStopJerk"));
                if (!m_pSetRoomStopJerk) m_DLLResultat=-2;

                VERIFY(m_pGetRoomStopJerk= (PGetRoomStopJerk) GetProcAddress(m_LStep4,"LSX_GetRoomStopJerk"));
                if (!m_pGetRoomStopJerk) m_DLLResultat=-2;

                VERIFY(m_pSetRoomAccel= (PSetRoomAccel) GetProcAddress(m_LStep4,"LSX_SetRoomAccel"));
                if (!m_pSetRoomAccel) m_DLLResultat=-2;

                VERIFY(m_pGetRoomAccel= (PGetRoomAccel) GetProcAddress(m_LStep4,"LSX_GetRoomAccel"));
                if (!m_pGetRoomAccel) m_DLLResultat=-2;

                VERIFY(m_pSetRoomDecel= (PSetRoomDecel) GetProcAddress(m_LStep4,"LSX_SetRoomDecel"));
                if (!m_pSetRoomDecel) m_DLLResultat=-2;

                VERIFY(m_pGetRoomDecel= (PGetRoomDecel) GetProcAddress(m_LStep4,"LSX_GetRoomDecel"));
                if (!m_pGetRoomDecel) m_DLLResultat=-2;

                VERIFY(m_pSetRoomStopDecel= (PSetRoomStopDecel) GetProcAddress(m_LStep4,"LSX_SetRoomStopDecel"));
                if (!m_pSetRoomStopDecel) m_DLLResultat=-2;

                VERIFY(m_pGetRoomStopDecel= (PGetRoomStopDecel) GetProcAddress(m_LStep4,"LSX_GetRoomStopDecel"));
                if (!m_pGetRoomStopDecel) m_DLLResultat=-2;

                VERIFY(m_pSetRoomVel= (PSetRoomVel) GetProcAddress(m_LStep4,"LSX_SetRoomVel"));
                if (!m_pSetRoomVel) m_DLLResultat=-2;

                VERIFY(m_pGetRoomVel= (PGetRoomVel) GetProcAddress(m_LStep4,"LSX_GetRoomVel"));
                if (!m_pGetRoomVel) m_DLLResultat=-2;

                VERIFY(m_pSetReduction= (PSetReduction) GetProcAddress(m_LStep4,"LSX_SetReduction"));
                if (!m_pSetReduction) m_DLLResultat=-2;

                VERIFY(m_pSetDelay= (PSetDelay) GetProcAddress(m_LStep4,"LSX_SetDelay"));
                if (!m_pSetDelay) m_DLLResultat=-2;

                VERIFY(m_pSetSwitchPolarity= (PSetSwitchPolarity) GetProcAddress(m_LStep4,"LSX_SetSwitchPolarity"));
                if (!m_pSetSwitchPolarity) m_DLLResultat=-2;

                VERIFY(m_pSetSwitchActive= (PSetSwitchActive) GetProcAddress(m_LStep4,"LSX_SetSwitchActive"));
                if (!m_pSetSwitchActive) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickOn= (PSetJoystickOn) GetProcAddress(m_LStep4,"LSX_SetJoystickOn"));
                if (!m_pSetJoystickOn) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickOff= (PSetJoystickOff) GetProcAddress(m_LStep4,"LSX_SetJoystickOff"));
                if (!m_pSetJoystickOff) m_DLLResultat=-2;

                VERIFY(m_pSoftwareReset= (PSoftwareReset) GetProcAddress(m_LStep4,"LSX_SoftwareReset"));
                if (!m_pSoftwareReset) m_DLLResultat=-2;

                VERIFY(m_pSetDigitalOutput= (PSetDigitalOutput) GetProcAddress(m_LStep4,"LSX_SetDigitalOutput"));
                if (!m_pSetDigitalOutput) m_DLLResultat=-2;

                VERIFY(m_pGetDigitalInputs= (PGetDigitalInputs) GetProcAddress(m_LStep4,"LSX_GetDigitalInputs"));
                if (!m_pGetDigitalInputs) m_DLLResultat=-2;

                VERIFY(m_pSetAnalogOutput= (PSetAnalogOutput) GetProcAddress(m_LStep4,"LSX_SetAnalogOutput"));
                if (!m_pSetAnalogOutput) m_DLLResultat=-2;

                VERIFY(m_pGetAnalogInput= (PGetAnalogInput) GetProcAddress(m_LStep4,"LSX_GetAnalogInput"));
                if (!m_pGetAnalogInput) m_DLLResultat=-2;

                VERIFY(m_pSetLimit= (PSetLimit) GetProcAddress(m_LStep4,"LSX_SetLimit"));
                if (!m_pSetLimit) m_DLLResultat=-2;

                VERIFY(m_pSetLimitControl= (PSetLimitControl) GetProcAddress(m_LStep4,"LSX_SetLimitControl"));
                if (!m_pSetLimitControl) m_DLLResultat=-2;

                VERIFY(m_pGetPos= (PGetPos) GetProcAddress(m_LStep4,"LSX_GetPos"));
                if (!m_pGetPos) m_DLLResultat=-2;

                VERIFY(m_pGetStatus= (PGetStatus) GetProcAddress(m_LStep4,"LSX_GetStatus"));
                if (!m_pGetStatus) m_DLLResultat=-2;

                VERIFY(m_pGetStatusW= (PGetStatusW) GetProcAddress(m_LStep4,"LSX_GetStatusW"));
                if (!m_pGetStatusW) m_DLLResultat=-2;

                VERIFY(m_pGetEncoderMask= (PGetEncoderMask) GetProcAddress(m_LStep4,"LSX_GetEncoderMask"));
                if (!m_pGetEncoderMask) m_DLLResultat=-2;

                VERIFY(m_pStopAxes= (PStopAxes) GetProcAddress(m_LStep4,"LSX_StopAxes"));
                if (!m_pStopAxes) m_DLLResultat=-2;

                VERIFY(m_pSetAbortFlag= (PSetAbortFlag) GetProcAddress(m_LStep4,"LSX_SetAbortFlag"));
                if (!m_pSetAbortFlag) m_DLLResultat=-2;

                VERIFY(m_pMoveRelSingleAxis= (PMoveRelSingleAxis) GetProcAddress(m_LStep4,"LSX_MoveRelSingleAxis"));
                if (!m_pMoveRelSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pMoveAbsSingleAxis= (PMoveAbsSingleAxis) GetProcAddress(m_LStep4,"LSX_MoveAbsSingleAxis"));
                if (!m_pMoveAbsSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pMoveSequence= (PMoveSequence) GetProcAddress(m_LStep4,"LSX_MoveSequence"));
                if (!m_pMoveSequence) m_DLLResultat=-2;

                VERIFY(m_pSetControlPars= (PSetControlPars) GetProcAddress(m_LStep4,"LSX_SetControlPars"));
                if (!m_pSetControlPars) m_DLLResultat=-2;

                VERIFY(m_pSetMotorCurrent= (PSetMotorCurrent) GetProcAddress(m_LStep4,"LSX_SetMotorCurrent"));
                if (!m_pSetMotorCurrent) m_DLLResultat=-2;

                VERIFY(m_pSetMotorAutoKommCurrent= (PSetMotorAutoKommCurrent) GetProcAddress(m_LStep4,"LSX_SetMotorAutoKommCurrent"));
                if (!m_pSetMotorAutoKommCurrent) m_DLLResultat=-2;

                VERIFY(m_pGetMotorAutoKommCurrent= (PGetMotorAutoKommCurrent) GetProcAddress(m_LStep4,"LSX_GetMotorAutoKommCurrent"));
                if (!m_pGetMotorAutoKommCurrent) m_DLLResultat=-2;

                VERIFY(m_pSetMotorpeakCurrent= (PSetMotorpeakCurrent) GetProcAddress(m_LStep4,"LSX_SetMotorpeakCurrent"));
                if (!m_pSetMotorpeakCurrent) m_DLLResultat=-2;

                VERIFY(m_pGetMotorpeakCurrent= (PGetMotorpeakCurrent) GetProcAddress(m_LStep4,"LSX_GetMotorpeakCurrent"));
                if (!m_pGetMotorpeakCurrent) m_DLLResultat=-2;

                VERIFY(m_pSetMotorpeakCurrentTime= (PSetMotorpeakCurrentTime) GetProcAddress(m_LStep4,"LSX_SetMotorpeakCurrentTime"));
                if (!m_pSetMotorpeakCurrentTime) m_DLLResultat=-2;

                VERIFY(m_pGetMotorpeakCurrentTime= (PGetMotorpeakCurrentTime) GetProcAddress(m_LStep4,"LSX_GetMotorpeakCurrentTime"));
                if (!m_pGetMotorpeakCurrentTime) m_DLLResultat=-2;

                VERIFY(m_pSetMotorIITCheck= (PSetMotorIITCheck) GetProcAddress(m_LStep4,"LSX_SetMotorIITCheck"));
                if (!m_pSetMotorIITCheck) m_DLLResultat=-2;

                VERIFY(m_pGetMotorIITCheck= (PGetMotorIITCheck) GetProcAddress(m_LStep4,"LSX_GetMotorIITCheck"));
                if (!m_pGetMotorIITCheck) m_DLLResultat=-2;

                VERIFY(m_pSetVelSingleAxis= (PSetVelSingleAxis) GetProcAddress(m_LStep4,"LSX_SetVelSingleAxis"));
                if (!m_pSetVelSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pSetAccelSingleAxis= (PSetAccelSingleAxis) GetProcAddress(m_LStep4,"LSX_SetAccelSingleAxis"));
                if (!m_pSetAccelSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pCalibrateEx= (PCalibrateEx) GetProcAddress(m_LStep4,"LSX_CalibrateEx"));
                if (!m_pCalibrateEx) m_DLLResultat=-2;

                VERIFY(m_pRMeasureEx= (PRMeasureEx) GetProcAddress(m_LStep4,"LSX_RMeasureEx"));
                if (!m_pRMeasureEx) m_DLLResultat=-2;

                VERIFY(m_pSetShowProt= (PSetShowProt) GetProcAddress(m_LStep4,"LSX_SetShowProt"));
                if (!m_pSetShowProt) m_DLLResultat=-2;

                VERIFY(m_pGetAnalogInputs2= (PGetAnalogInputs2) GetProcAddress(m_LStep4,"LSX_GetAnalogInputs2"));
                if (!m_pGetAnalogInputs2) m_DLLResultat=-2;

                VERIFY(m_pSendString= (PSendString) GetProcAddress(m_LStep4,"LSX_SendString"));
                if (!m_pSendString) m_DLLResultat=-2;

                VERIFY(m_pSendStringW= (PSendStringW) GetProcAddress(m_LStep4,"LSX_SendStringW"));
                if (!m_pSendStringW) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedPoti= (PSetSpeedPoti) GetProcAddress(m_LStep4,"LSX_SetSpeedPoti"));
                if (!m_pSetSpeedPoti) m_DLLResultat=-2;

                VERIFY(m_pSetTVRMode= (PSetTVRMode) GetProcAddress(m_LStep4,"LSX_SetTVRMode"));
                if (!m_pSetTVRMode) m_DLLResultat=-2;

                VERIFY(m_pSetAutoStatus= (PSetAutoStatus) GetProcAddress(m_LStep4,"LSX_SetAutoStatus"));
                if (!m_pSetAutoStatus) m_DLLResultat=-2;

                VERIFY(m_pGetStatusAxis= (PGetStatusAxis) GetProcAddress(m_LStep4,"LSX_GetStatusAxis"));
                if (!m_pGetStatusAxis) m_DLLResultat=-2;

                VERIFY(m_pGetStatusAxisW= (PGetStatusAxisW) GetProcAddress(m_LStep4,"LSX_GetStatusAxisW"));
                if (!m_pGetStatusAxisW) m_DLLResultat=-2;

                VERIFY(m_pSetDigIO_Off= (PSetDigIO_Off) GetProcAddress(m_LStep4,"LSX_SetDigIO_Off"));
                if (!m_pSetDigIO_Off) m_DLLResultat=-2;

                VERIFY(m_pSetDigIO_Polarity= (PSetDigIO_Polarity) GetProcAddress(m_LStep4,"LSX_SetDigIO_Polarity"));
                if (!m_pSetDigIO_Polarity) m_DLLResultat=-2;

                VERIFY(m_pSetDigIO_EmergencyStop= (PSetDigIO_EmergencyStop) GetProcAddress(m_LStep4,"LSX_SetDigIO_EmergencyStop"));
                if (!m_pSetDigIO_EmergencyStop) m_DLLResultat=-2;

                VERIFY(m_pSetDigIO_Distance= (PSetDigIO_Distance) GetProcAddress(m_LStep4,"LSX_SetDigIO_Distance"));
                if (!m_pSetDigIO_Distance) m_DLLResultat=-2;

                VERIFY(m_pSetDimensions= (PSetDimensions) GetProcAddress(m_LStep4,"LSX_SetDimensions"));
                if (!m_pSetDimensions) m_DLLResultat=-2;

                VERIFY(m_pMoveRelShort= (PMoveRelShort) GetProcAddress(m_LStep4,"LSX_MoveRelShort"));
                if (!m_pMoveRelShort) m_DLLResultat=-2;

                VERIFY(m_pSetEncoderPeriod= (PSetEncoderPeriod) GetProcAddress(m_LStep4,"LSX_SetEncoderPeriod"));
                if (!m_pSetEncoderPeriod) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickDir= (PSetJoystickDir) GetProcAddress(m_LStep4,"LSX_SetJoystickDir"));
                if (!m_pSetJoystickDir) m_DLLResultat=-2;

                VERIFY(m_pSetEncoderMask= (PSetEncoderMask) GetProcAddress(m_LStep4,"LSX_SetEncoderMask"));
                if (!m_pSetEncoderMask) m_DLLResultat=-2;

                VERIFY(m_pSetGear= (PSetGear) GetProcAddress(m_LStep4,"LSX_SetGear"));
                if (!m_pSetGear) m_DLLResultat=-2;

                VERIFY(m_pSetHandWheelOn= (PSetHandWheelOn) GetProcAddress(m_LStep4,"LSX_SetHandWheelOn"));
                if (!m_pSetHandWheelOn) m_DLLResultat=-2;

                VERIFY(m_pSetHandWheelOff= (PSetHandWheelOff) GetProcAddress(m_LStep4,"LSX_SetHandWheelOff"));
                if (!m_pSetHandWheelOff) m_DLLResultat=-2;

                VERIFY(m_pSetFactorTVR= (PSetFactorTVR) GetProcAddress(m_LStep4,"LSX_SetFactorTVR"));
                if (!m_pSetFactorTVR) m_DLLResultat=-2;

                VERIFY(m_pSetController= (PSetController) GetProcAddress(m_LStep4,"LSX_SetController"));
                if (!m_pSetController) m_DLLResultat=-2;

                VERIFY(m_pSetControllerCall= (PSetControllerCall) GetProcAddress(m_LStep4,"LSX_SetControllerCall"));
                if (!m_pSetControllerCall) m_DLLResultat=-2;

                VERIFY(m_pSetControllerSteps= (PSetControllerSteps) GetProcAddress(m_LStep4,"LSX_SetControllerSteps"));
                if (!m_pSetControllerSteps) m_DLLResultat=-2;

                VERIFY(m_pSetControllerFactor= (PSetControllerFactor) GetProcAddress(m_LStep4,"LSX_SetControllerFactor"));
                if (!m_pSetControllerFactor) m_DLLResultat=-2;

                VERIFY(m_pSetControllerTWDelay= (PSetControllerTWDelay) GetProcAddress(m_LStep4,"LSX_SetControllerTWDelay"));
                if (!m_pSetControllerTWDelay) m_DLLResultat=-2;

                VERIFY(m_pSetEncoderRefSignal= (PSetEncoderRefSignal) GetProcAddress(m_LStep4,"LSX_SetEncoderRefSignal"));
                if (!m_pSetEncoderRefSignal) m_DLLResultat=-2;

                VERIFY(m_pSetEncoderPosition= (PSetEncoderPosition) GetProcAddress(m_LStep4,"LSX_SetEncoderPosition"));
                if (!m_pSetEncoderPosition) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStr= (PGetVersionStr) GetProcAddress(m_LStep4,"LSX_GetVersionStr"));
                if (!m_pGetVersionStr) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStrW= (PGetVersionStrW) GetProcAddress(m_LStep4,"LSX_GetVersionStrW"));
                if (!m_pGetVersionStrW) m_DLLResultat=-2;

                VERIFY(m_pGetError= (PGetError) GetProcAddress(m_LStep4,"LSX_GetError"));
                if (!m_pGetError) m_DLLResultat=-2;

                VERIFY(m_pGetPosSingleAxis= (PGetPosSingleAxis) GetProcAddress(m_LStep4,"LSX_GetPosSingleAxis"));
                if (!m_pGetPosSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pSetDistance= (PSetDistance) GetProcAddress(m_LStep4,"LSX_SetDistance"));
                if (!m_pSetDistance) m_DLLResultat=-2;

                VERIFY(m_pGetPosEx= (PGetPosEx) GetProcAddress(m_LStep4,"LSX_GetPosEx"));
                if (!m_pGetPosEx) m_DLLResultat=-2;

                VERIFY(m_pSetShowCmdList= (PSetShowCmdList) GetProcAddress(m_LStep4,"LSX_SetShowCmdList"));
                if (!m_pSetShowCmdList) m_DLLResultat=-2;

                VERIFY(m_pSetWriteLogText= (PSetWriteLogText) GetProcAddress(m_LStep4,"LSX_SetWriteLogText"));
                if (!m_pSetWriteLogText) m_DLLResultat=-2;

                VERIFY(m_pSetControllerTimeout= (PSetControllerTimeout) GetProcAddress(m_LStep4,"LSX_SetControllerTimeout"));
                if (!m_pSetControllerTimeout) m_DLLResultat=-2;

                VERIFY(m_pSetEncoderActive= (PSetEncoderActive) GetProcAddress(m_LStep4,"LSX_SetEncoderActive"));
                if (!m_pSetEncoderActive) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshotCount= (PGetSnapshotCount) GetProcAddress(m_LStep4,"LSX_GetSnapshotCount"));
                if (!m_pGetSnapshotCount) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshotPos= (PGetSnapshotPos) GetProcAddress(m_LStep4,"LSX_GetSnapshotPos"));
                if (!m_pGetSnapshotPos) m_DLLResultat=-2;

                VERIFY(m_pSetCorrTblOff= (PSetCorrTblOff) GetProcAddress(m_LStep4,"LSX_SetCorrTblOff"));
                if (!m_pSetCorrTblOff) m_DLLResultat=-2;

                VERIFY(m_pSetCorrTblOn= (PSetCorrTblOn) GetProcAddress(m_LStep4,"LSX_SetCorrTblOn"));
                if (!m_pSetCorrTblOn) m_DLLResultat=-2;

                VERIFY(m_pSetCorrTblOnW= (PSetCorrTblOnW) GetProcAddress(m_LStep4,"LSX_SetCorrTblOnW"));
                if (!m_pSetCorrTblOnW) m_DLLResultat=-2;

                VERIFY(m_pSetFactorMode= (PSetFactorMode) GetProcAddress(m_LStep4,"LSX_SetFactorMode"));
                if (!m_pSetFactorMode) m_DLLResultat=-2;

                VERIFY(m_pSetSnapshot= (PSetSnapshot) GetProcAddress(m_LStep4,"LSX_SetSnapshot"));
                if (!m_pSetSnapshot) m_DLLResultat=-2;

                VERIFY(m_pSetSnapshotPar= (PSetSnapshotPar) GetProcAddress(m_LStep4,"LSX_SetSnapshotPar"));
                if (!m_pSetSnapshotPar) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger= (PSetTrigger) GetProcAddress(m_LStep4,"LSX_SetTrigger"));
                if (!m_pSetTrigger) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_= (PSetTrigger_) GetProcAddress(m_LStep4,"LSX_SetTrigger_"));
                if (!m_pSetTrigger_) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerPar= (PSetTriggerPar) GetProcAddress(m_LStep4,"LSX_SetTriggerPar"));
                if (!m_pSetTriggerPar) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoPar= (PSetTrigger_TwoPar) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoPar"));
                if (!m_pSetTrigger_TwoPar) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerSource= (PSetTriggerSource) GetProcAddress(m_LStep4,"LSX_SetTriggerSource"));
                if (!m_pSetTriggerSource) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerSource= (PGetTriggerSource) GetProcAddress(m_LStep4,"LSX_GetTriggerSource"));
                if (!m_pGetTriggerSource) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoSource= (PSetTrigger_TwoSource) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoSource"));
                if (!m_pSetTrigger_TwoSource) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoSource= (PGetTrigger_TwoSource) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoSource"));
                if (!m_pGetTrigger_TwoSource) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerHysterese= (PSetTriggerHysterese) GetProcAddress(m_LStep4,"LSX_SetTriggerHysterese"));
                if (!m_pSetTriggerHysterese) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerHysterese= (PGetTriggerHysterese) GetProcAddress(m_LStep4,"LSX_GetTriggerHysterese"));
                if (!m_pGetTriggerHysterese) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoHysterese= (PSetTrigger_TwoHysterese) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoHysterese"));
                if (!m_pSetTrigger_TwoHysterese) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoHysterese= (PGetTrigger_TwoHysterese) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoHysterese"));
                if (!m_pGetTrigger_TwoHysterese) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerPLength= (PSetTriggerPLength) GetProcAddress(m_LStep4,"LSX_SetTriggerPLength"));
                if (!m_pSetTriggerPLength) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerPLength= (PGetTriggerPLength) GetProcAddress(m_LStep4,"LSX_GetTriggerPLength"));
                if (!m_pGetTriggerPLength) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoPLength= (PSetTrigger_TwoPLength) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoPLength"));
                if (!m_pSetTrigger_TwoPLength) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoPLength= (PGetTrigger_TwoPLength) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoPLength"));
                if (!m_pGetTrigger_TwoPLength) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerPulsCount= (PSetTriggerPulsCount) GetProcAddress(m_LStep4,"LSX_SetTriggerPulsCount"));
                if (!m_pSetTriggerPulsCount) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerPulsCount= (PGetTriggerPulsCount) GetProcAddress(m_LStep4,"LSX_GetTriggerPulsCount"));
                if (!m_pGetTriggerPulsCount) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoPulsCount= (PSetTrigger_TwoPulsCount) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoPulsCount"));
                if (!m_pSetTrigger_TwoPulsCount) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoPulsCount= (PGetTrigger_TwoPulsCount) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoPulsCount"));
                if (!m_pGetTrigger_TwoPulsCount) m_DLLResultat=-2;

                VERIFY(m_pSetConfigurated= (PSetConfigurated) GetProcAddress(m_LStep4,"LSX_SetConfigurated"));
                if (!m_pSetConfigurated) m_DLLResultat=-2;

                VERIFY(m_pGetConfigurated= (PGetConfigurated) GetProcAddress(m_LStep4,"LSX_GetConfigurated"));
                if (!m_pGetConfigurated) m_DLLResultat=-2;

                VERIFY(m_pSetStopMode= (PSetStopMode) GetProcAddress(m_LStep4,"LSX_SetStopMode"));
                if (!m_pSetStopMode) m_DLLResultat=-2;

                VERIFY(m_pGetStopMode= (PGetStopMode) GetProcAddress(m_LStep4,"LSX_GetStopMode"));
                if (!m_pGetStopMode) m_DLLResultat=-2;

                VERIFY(m_pSetStopSwitchOffDelay = (PSetStopSwitchOffDelay ) GetProcAddress(m_LStep4,"LSX_SetStopSwitchOffDelay "));
                if (!m_pSetStopSwitchOffDelay ) m_DLLResultat=-2;

                VERIFY(m_pGetStopSwitchOffDelay = (PGetStopSwitchOffDelay ) GetProcAddress(m_LStep4,"LSX_GetStopSwitchOffDelay "));
                if (!m_pGetStopSwitchOffDelay ) m_DLLResultat=-2;

                VERIFY(m_pSetLanguage= (PSetLanguage) GetProcAddress(m_LStep4,"LSX_SetLanguage"));
                if (!m_pSetLanguage) m_DLLResultat=-2;

                VERIFY(m_pSetLanguageW= (PSetLanguageW) GetProcAddress(m_LStep4,"LSX_SetLanguageW"));
                if (!m_pSetLanguageW) m_DLLResultat=-2;

                VERIFY(m_pGetSwitches= (PGetSwitches) GetProcAddress(m_LStep4,"LSX_GetSwitches"));
                if (!m_pGetSwitches) m_DLLResultat=-2;

                VERIFY(m_pGetSerialNr= (PGetSerialNr) GetProcAddress(m_LStep4,"LSX_GetSerialNr"));
                if (!m_pGetSerialNr) m_DLLResultat=-2;

                VERIFY(m_pGetSerialNrW= (PGetSerialNrW) GetProcAddress(m_LStep4,"LSX_GetSerialNrW"));
                if (!m_pGetSerialNrW) m_DLLResultat=-2;

                VERIFY(m_pSetCSOffset= (PSetCSOffset) GetProcAddress(m_LStep4,"LSX_SetCSOffset"));
                if (!m_pSetCSOffset) m_DLLResultat=-2;

                VERIFY(m_pGetCSOffset= (PGetCSOffset) GetProcAddress(m_LStep4,"LSX_GetCSOffset"));
                if (!m_pGetCSOffset) m_DLLResultat=-2;

                VERIFY(m_pSetCalibRMOffsetSWAct= (PSetCalibRMOffsetSWAct) GetProcAddress(m_LStep4,"LSX_SetCalibRMOffsetSWAct"));
                if (!m_pSetCalibRMOffsetSWAct) m_DLLResultat=-2;

                VERIFY(m_pGetCalibRMOffsetSWAct= (PGetCalibRMOffsetSWAct) GetProcAddress(m_LStep4,"LSX_GetCalibRMOffsetSWAct"));
                if (!m_pGetCalibRMOffsetSWAct) m_DLLResultat=-2;

                VERIFY(m_pMoveAbsV= (PMoveAbsV) GetProcAddress(m_LStep4,"LSX_MoveAbsV"));
                if (!m_pMoveAbsV) m_DLLResultat=-2;

                VERIFY(m_pMoveAbsVW= (PMoveAbsVW) GetProcAddress(m_LStep4,"LSX_MoveAbsVW"));
                if (!m_pMoveAbsVW) m_DLLResultat=-2;

                VERIFY(m_pMoveRelV= (PMoveRelV) GetProcAddress(m_LStep4,"LSX_MoveRelV"));
                if (!m_pMoveRelV) m_DLLResultat=-2;

                VERIFY(m_pMoveRelVW= (PMoveRelVW) GetProcAddress(m_LStep4,"LSX_MoveRelVW"));
                if (!m_pMoveRelVW) m_DLLResultat=-2;

                VERIFY(m_pGetDeviationValue= (PGetDeviationValue) GetProcAddress(m_LStep4,"LSX_GetDeviationValue"));
                if (!m_pGetDeviationValue) m_DLLResultat=-2;

                VERIFY(m_pSetAutoKomm= (PSetAutoKomm) GetProcAddress(m_LStep4,"LSX_SetAutoKomm"));
                if (!m_pSetAutoKomm) m_DLLResultat=-2;

                VERIFY(m_pSetAutoKommW= (PSetAutoKommW) GetProcAddress(m_LStep4,"LSX_SetAutoKommW"));
                if (!m_pSetAutoKommW) m_DLLResultat=-2;

                VERIFY(m_pGetAutoKomm= (PGetAutoKomm) GetProcAddress(m_LStep4,"LSX_GetAutoKomm"));
                if (!m_pGetAutoKomm) m_DLLResultat=-2;

                VERIFY(m_pGetAutoKommResult= (PGetAutoKommResult) GetProcAddress(m_LStep4,"LSX_GetAutoKommResult"));
                if (!m_pGetAutoKommResult) m_DLLResultat=-2;

                VERIFY(m_pSetTablePos= (PSetTablePos) GetProcAddress(m_LStep4,"LSX_SetTablePos"));
                if (!m_pSetTablePos) m_DLLResultat=-2;

                VERIFY(m_pGetTablePos= (PGetTablePos) GetProcAddress(m_LStep4,"LSX_GetTablePos"));
                if (!m_pGetTablePos) m_DLLResultat=-2;

                VERIFY(m_pSetIndexTableDivider= (PSetIndexTableDivider) GetProcAddress(m_LStep4,"LSX_SetIndexTableDivider"));
                if (!m_pSetIndexTableDivider) m_DLLResultat=-2;

                VERIFY(m_pGetIndexTableDivider= (PGetIndexTableDivider) GetProcAddress(m_LStep4,"LSX_GetIndexTableDivider"));
                if (!m_pGetIndexTableDivider) m_DLLResultat=-2;

                VERIFY(m_pMoveTablePosAbs= (PMoveTablePosAbs) GetProcAddress(m_LStep4,"LSX_MoveTablePosAbs"));
                if (!m_pMoveTablePosAbs) m_DLLResultat=-2;

                VERIFY(m_pMoveTablePosAbsW= (PMoveTablePosAbsW) GetProcAddress(m_LStep4,"LSX_MoveTablePosAbsW"));
                if (!m_pMoveTablePosAbsW) m_DLLResultat=-2;

                VERIFY(m_pMoveTablePosRel= (PMoveTablePosRel) GetProcAddress(m_LStep4,"LSX_MoveTablePosRel"));
                if (!m_pMoveTablePosRel) m_DLLResultat=-2;

                VERIFY(m_pMoveTablePosRelW= (PMoveTablePosRelW) GetProcAddress(m_LStep4,"LSX_MoveTablePosRelW"));
                if (!m_pMoveTablePosRelW) m_DLLResultat=-2;

                VERIFY(m_pMoveIndexTable= (PMoveIndexTable) GetProcAddress(m_LStep4,"LSX_MoveIndexTable"));
                if (!m_pMoveIndexTable) m_DLLResultat=-2;

                VERIFY(m_pMoveIndexTableW= (PMoveIndexTableW) GetProcAddress(m_LStep4,"LSX_MoveIndexTableW"));
                if (!m_pMoveIndexTableW) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedEnable= (PSetSpeedEnable) GetProcAddress(m_LStep4,"LSX_SetSpeedEnable"));
                if (!m_pSetSpeedEnable) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedEnable= (PGetSpeedEnable) GetProcAddress(m_LStep4,"LSX_GetSpeedEnable"));
                if (!m_pGetSpeedEnable) m_DLLResultat=-2;

                VERIFY(m_pSetSpeed= (PSetSpeed) GetProcAddress(m_LStep4,"LSX_SetSpeed"));
                if (!m_pSetSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetSpeed= (PGetSpeed) GetProcAddress(m_LStep4,"LSX_GetSpeed"));
                if (!m_pGetSpeed) m_DLLResultat=-2;

                VERIFY(m_pSetMixedMoveAxisMode= (PSetMixedMoveAxisMode) GetProcAddress(m_LStep4,"LSX_SetMixedMoveAxisMode"));
                if (!m_pSetMixedMoveAxisMode) m_DLLResultat=-2;

                VERIFY(m_pGetMixedMoveAxisMode= (PGetMixedMoveAxisMode) GetProcAddress(m_LStep4,"LSX_GetMixedMoveAxisMode"));
                if (!m_pGetMixedMoveAxisMode) m_DLLResultat=-2;

                VERIFY(m_pMixedMoveAbs= (PMixedMoveAbs) GetProcAddress(m_LStep4,"LSX_MixedMoveAbs"));
                if (!m_pMixedMoveAbs) m_DLLResultat=-2;

                VERIFY(m_pMixedMoveAbsW= (PMixedMoveAbsW) GetProcAddress(m_LStep4,"LSX_MixedMoveAbsW"));
                if (!m_pMixedMoveAbsW) m_DLLResultat=-2;

                VERIFY(m_pMixedMoveRel= (PMixedMoveRel) GetProcAddress(m_LStep4,"LSX_MixedMoveRel"));
                if (!m_pMixedMoveRel) m_DLLResultat=-2;

                VERIFY(m_pMixedMoveRelW= (PMixedMoveRelW) GetProcAddress(m_LStep4,"LSX_MixedMoveRelW"));
                if (!m_pMixedMoveRelW) m_DLLResultat=-2;

                VERIFY(m_pSetMixedMovePos= (PSetMixedMovePos) GetProcAddress(m_LStep4,"LSX_SetMixedMovePos"));
                if (!m_pSetMixedMovePos) m_DLLResultat=-2;

                VERIFY(m_pGetMixedMovePos= (PGetMixedMovePos) GetProcAddress(m_LStep4,"LSX_GetMixedMovePos"));
                if (!m_pGetMixedMovePos) m_DLLResultat=-2;

                VERIFY(m_pSetMixedMoveAmpl= (PSetMixedMoveAmpl) GetProcAddress(m_LStep4,"LSX_SetMixedMoveAmpl"));
                if (!m_pSetMixedMoveAmpl) m_DLLResultat=-2;

                VERIFY(m_pGetMixedMoveAmpl= (PGetMixedMoveAmpl) GetProcAddress(m_LStep4,"LSX_GetMixedMoveAmpl"));
                if (!m_pGetMixedMoveAmpl) m_DLLResultat=-2;

                VERIFY(m_pSetMoveSeqStatusPos= (PSetMoveSeqStatusPos) GetProcAddress(m_LStep4,"LSX_SetMoveSeqStatusPos"));
                if (!m_pSetMoveSeqStatusPos) m_DLLResultat=-2;

                VERIFY(m_pGetMoveSeqStatusPos= (PGetMoveSeqStatusPos) GetProcAddress(m_LStep4,"LSX_GetMoveSeqStatusPos"));
                if (!m_pGetMoveSeqStatusPos) m_DLLResultat=-2;

                VERIFY(m_pSetMoveSeqStatus= (PSetMoveSeqStatus) GetProcAddress(m_LStep4,"LSX_SetMoveSeqStatus"));
                if (!m_pSetMoveSeqStatus) m_DLLResultat=-2;

                VERIFY(m_pSetMoveSeqStatusW= (PSetMoveSeqStatusW) GetProcAddress(m_LStep4,"LSX_SetMoveSeqStatusW"));
                if (!m_pSetMoveSeqStatusW) m_DLLResultat=-2;

                VERIFY(m_pGetMoveSeqStatus= (PGetMoveSeqStatus) GetProcAddress(m_LStep4,"LSX_GetMoveSeqStatus"));
                if (!m_pGetMoveSeqStatus) m_DLLResultat=-2;

                VERIFY(m_pSetMoveSeqVar= (PSetMoveSeqVar) GetProcAddress(m_LStep4,"LSX_SetMoveSeqVar"));
                if (!m_pSetMoveSeqVar) m_DLLResultat=-2;

                VERIFY(m_pGetMoveSeqVar= (PGetMoveSeqVar) GetProcAddress(m_LStep4,"LSX_GetMoveSeqVar"));
                if (!m_pGetMoveSeqVar) m_DLLResultat=-2;

                VERIFY(m_pSetCalibOffset= (PSetCalibOffset) GetProcAddress(m_LStep4,"LSX_SetCalibOffset"));
                if (!m_pSetCalibOffset) m_DLLResultat=-2;

                VERIFY(m_pSetRMOffset= (PSetRMOffset) GetProcAddress(m_LStep4,"LSX_SetRMOffset"));
                if (!m_pSetRMOffset) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshotPosArray= (PGetSnapshotPosArray) GetProcAddress(m_LStep4,"LSX_GetSnapshotPosArray"));
                if (!m_pGetSnapshotPosArray) m_DLLResultat=-2;

                VERIFY(m_pSetAxisDirection= (PSetAxisDirection) GetProcAddress(m_LStep4,"LSX_SetAxisDirection"));
                if (!m_pSetAxisDirection) m_DLLResultat=-2;

                VERIFY(m_pSetCalibrateDir= (PSetCalibrateDir) GetProcAddress(m_LStep4,"LSX_SetCalibrateDir"));
                if (!m_pSetCalibrateDir) m_DLLResultat=-2;

                VERIFY(m_pLStepSave= (PLStepSave) GetProcAddress(m_LStep4,"LSX_LStepSave"));
                if (!m_pLStepSave) m_DLLResultat=-2;

                VERIFY(m_pSetBPZ= (PSetBPZ) GetProcAddress(m_LStep4,"LSX_SetBPZ"));
                if (!m_pSetBPZ) m_DLLResultat=-2;

                VERIFY(m_pSetBPZTrackballFactor= (PSetBPZTrackballFactor) GetProcAddress(m_LStep4,"LSX_SetBPZTrackballFactor"));
                if (!m_pSetBPZTrackballFactor) m_DLLResultat=-2;

                VERIFY(m_pSetBPZTrackballBackLash= (PSetBPZTrackballBackLash) GetProcAddress(m_LStep4,"LSX_SetBPZTrackballBackLash"));
                if (!m_pSetBPZTrackballBackLash) m_DLLResultat=-2;

                VERIFY(m_pSetBPZJoyspeed= (PSetBPZJoyspeed) GetProcAddress(m_LStep4,"LSX_SetBPZJoyspeed"));
                if (!m_pSetBPZJoyspeed) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickWindow= (PSetJoystickWindow) GetProcAddress(m_LStep4,"LSX_SetJoystickWindow"));
                if (!m_pSetJoystickWindow) m_DLLResultat=-2;

                VERIFY(m_pSetCurrentDelay= (PSetCurrentDelay) GetProcAddress(m_LStep4,"LSX_SetCurrentDelay"));
                if (!m_pSetCurrentDelay) m_DLLResultat=-2;

                VERIFY(m_pMoveEx= (PMoveEx) GetProcAddress(m_LStep4,"LSX_MoveEx"));
                if (!m_pMoveEx) m_DLLResultat=-2;

                VERIFY(m_pWaitForAxisStop= (PWaitForAxisStop) GetProcAddress(m_LStep4,"LSX_WaitForAxisStop"));
                if (!m_pWaitForAxisStop) m_DLLResultat=-2;

                VERIFY(m_pSendStringPosCmd= (PSendStringPosCmd) GetProcAddress(m_LStep4,"LSX_SendStringPosCmd"));
                if (!m_pSendStringPosCmd) m_DLLResultat=-2;

                VERIFY(m_pSendStringPosCmdW= (PSendStringPosCmdW) GetProcAddress(m_LStep4,"LSX_SendStringPosCmdW"));
                if (!m_pSendStringPosCmdW) m_DLLResultat=-2;

                VERIFY(m_pSetDigitalOutputs= (PSetDigitalOutputs) GetProcAddress(m_LStep4,"LSX_SetDigitalOutputs"));
                if (!m_pSetDigitalOutputs) m_DLLResultat=-2;

                VERIFY(m_pSetWriteLogTextFN= (PSetWriteLogTextFN) GetProcAddress(m_LStep4,"LSX_SetWriteLogTextFN"));
                if (!m_pSetWriteLogTextFN) m_DLLResultat=-2;

                VERIFY(m_pSetWriteLogTextFNW= (PSetWriteLogTextFNW) GetProcAddress(m_LStep4,"LSX_SetWriteLogTextFNW"));
                if (!m_pSetWriteLogTextFNW) m_DLLResultat=-2;

                VERIFY(m_pEnableGlobalLogging= (PEnableGlobalLogging) GetProcAddress(m_LStep4,"LSX_EnableGlobalLogging"));
                if (!m_pEnableGlobalLogging) m_DLLResultat=-2;

                VERIFY(m_pEnableGuiLogging= (PEnableGuiLogging) GetProcAddress(m_LStep4,"LSX_EnableGuiLogging"));
                if (!m_pEnableGuiLogging) m_DLLResultat=-2;

                VERIFY(m_pSetDigitalOutputsE= (PSetDigitalOutputsE) GetProcAddress(m_LStep4,"LSX_SetDigitalOutputsE"));
                if (!m_pSetDigitalOutputsE) m_DLLResultat=-2;

                VERIFY(m_pSetDigOutLinktoSignal= (PSetDigOutLinktoSignal) GetProcAddress(m_LStep4,"LSX_SetDigOutLinktoSignal"));
                if (!m_pSetDigOutLinktoSignal) m_DLLResultat=-2;

                VERIFY(m_pGetDigOutLinktoSignal= (PGetDigOutLinktoSignal) GetProcAddress(m_LStep4,"LSX_GetDigOutLinktoSignal"));
                if (!m_pGetDigOutLinktoSignal) m_DLLResultat=-2;

                VERIFY(m_pSetMonitoringVelFilter= (PSetMonitoringVelFilter) GetProcAddress(m_LStep4,"LSX_SetMonitoringVelFilter"));
                if (!m_pSetMonitoringVelFilter) m_DLLResultat=-2;

                VERIFY(m_pGetMonitoringVelFilter= (PGetMonitoringVelFilter) GetProcAddress(m_LStep4,"LSX_GetMonitoringVelFilter"));
                if (!m_pGetMonitoringVelFilter) m_DLLResultat=-2;

                VERIFY(m_pSetHaltSignalVel= (PSetHaltSignalVel) GetProcAddress(m_LStep4,"LSX_SetHaltSignalVel"));
                if (!m_pSetHaltSignalVel) m_DLLResultat=-2;

                VERIFY(m_pGetHaltSignalVel= (PGetHaltSignalVel) GetProcAddress(m_LStep4,"LSX_GetHaltSignalVel"));
                if (!m_pGetHaltSignalVel) m_DLLResultat=-2;

                VERIFY(m_pSetThresholdSignalVel= (PSetThresholdSignalVel) GetProcAddress(m_LStep4,"LSX_SetThresholdSignalVel"));
                if (!m_pSetThresholdSignalVel) m_DLLResultat=-2;

                VERIFY(m_pGetThresholdSignalVel= (PGetThresholdSignalVel) GetProcAddress(m_LStep4,"LSX_GetThresholdSignalVel"));
                if (!m_pGetThresholdSignalVel) m_DLLResultat=-2;

                VERIFY(m_pSetInvertDigOutSignal= (PSetInvertDigOutSignal) GetProcAddress(m_LStep4,"LSX_SetInvertDigOutSignal"));
                if (!m_pSetInvertDigOutSignal) m_DLLResultat=-2;

                VERIFY(m_pGetInvertDigOutSignal= (PGetInvertDigOutSignal) GetProcAddress(m_LStep4,"LSX_GetInvertDigOutSignal"));
                if (!m_pGetInvertDigOutSignal) m_DLLResultat=-2;

                VERIFY(m_pGetDigitalInputsE= (PGetDigitalInputsE) GetProcAddress(m_LStep4,"LSX_GetDigitalInputsE"));
                if (!m_pGetDigitalInputsE) m_DLLResultat=-2;

                VERIFY(m_pEnableCommandRetry= (PEnableCommandRetry) GetProcAddress(m_LStep4,"LSX_EnableCommandRetry"));
                if (!m_pEnableCommandRetry) m_DLLResultat=-2;

                VERIFY(m_pSetXYAxisComp= (PSetXYAxisComp) GetProcAddress(m_LStep4,"LSX_SetXYAxisComp"));
                if (!m_pSetXYAxisComp) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStrDet= (PGetVersionStrDet) GetProcAddress(m_LStep4,"LSX_GetVersionStrDet"));
                if (!m_pGetVersionStrDet) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStrDetW= (PGetVersionStrDetW) GetProcAddress(m_LStep4,"LSX_GetVersionStrDetW"));
                if (!m_pGetVersionStrDetW) m_DLLResultat=-2;

                VERIFY(m_pGetAPIVersion= (PGetAPIVersion) GetProcAddress(m_LStep4,"LSX_GetAPIVersion"));
                if (!m_pGetAPIVersion) m_DLLResultat=-2;

                VERIFY(m_pGetAPIVersionW= (PGetAPIVersionW) GetProcAddress(m_LStep4,"LSX_GetAPIVersionW"));
                if (!m_pGetAPIVersionW) m_DLLResultat=-2;

                VERIFY(m_pSetCommandTimeout= (PSetCommandTimeout) GetProcAddress(m_LStep4,"LSX_SetCommandTimeout"));
                if (!m_pSetCommandTimeout) m_DLLResultat=-2;

                VERIFY(m_pSetExtValue= (PSetExtValue) GetProcAddress(m_LStep4,"LSX_SetExtValue"));
                if (!m_pSetExtValue) m_DLLResultat=-2;

                VERIFY(m_pFlushBuffer= (PFlushBuffer) GetProcAddress(m_LStep4,"LSX_FlushBuffer"));
                if (!m_pFlushBuffer) m_DLLResultat=-2;

                VERIFY(m_pSetProcessMessagesProc= (PSetProcessMessagesProc) GetProcAddress(m_LStep4,"LSX_SetProcessMessagesProc"));
                if (!m_pSetProcessMessagesProc) m_DLLResultat=-2;

                VERIFY(m_pGetEEPRomValue= (PGetEEPRomValue) GetProcAddress(m_LStep4,"LSX_GetEEPRomValue"));
                if (!m_pGetEEPRomValue) m_DLLResultat=-2;

                VERIFY(m_pSetEEPRomValue= (PSetEEPRomValue) GetProcAddress(m_LStep4,"LSX_SetEEPRomValue"));
                if (!m_pSetEEPRomValue) m_DLLResultat=-2;

                VERIFY(m_pGetXYAxisComp= (PGetXYAxisComp) GetProcAddress(m_LStep4,"LSX_GetXYAxisComp"));
                if (!m_pGetXYAxisComp) m_DLLResultat=-2;

                VERIFY(m_pGetDimensions= (PGetDimensions) GetProcAddress(m_LStep4,"LSX_GetDimensions"));
                if (!m_pGetDimensions) m_DLLResultat=-2;

                VERIFY(m_pGetPitch= (PGetPitch) GetProcAddress(m_LStep4,"LSX_GetPitch"));
                if (!m_pGetPitch) m_DLLResultat=-2;

                VERIFY(m_pGetGear= (PGetGear) GetProcAddress(m_LStep4,"LSX_GetGear"));
                if (!m_pGetGear) m_DLLResultat=-2;

                VERIFY(m_pGetVel= (PGetVel) GetProcAddress(m_LStep4,"LSX_GetVel"));
                if (!m_pGetVel) m_DLLResultat=-2;

                VERIFY(m_pGetAccel= (PGetAccel) GetProcAddress(m_LStep4,"LSX_GetAccel"));
                if (!m_pGetAccel) m_DLLResultat=-2;

                VERIFY(m_pSetVelFac= (PSetVelFac) GetProcAddress(m_LStep4,"LSX_SetVelFac"));
                if (!m_pSetVelFac) m_DLLResultat=-2;

                VERIFY(m_pSetVelFacSingleAxis= (PSetVelFacSingleAxis) GetProcAddress(m_LStep4,"LSX_SetVelFacSingleAxis"));
                if (!m_pSetVelFacSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pGetVelFac= (PGetVelFac) GetProcAddress(m_LStep4,"LSX_GetVelFac"));
                if (!m_pGetVelFac) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedPoti= (PGetSpeedPoti) GetProcAddress(m_LStep4,"LSX_GetSpeedPoti"));
                if (!m_pGetSpeedPoti) m_DLLResultat=-2;

                VERIFY(m_pGetMotorCurrent= (PGetMotorCurrent) GetProcAddress(m_LStep4,"LSX_GetMotorCurrent"));
                if (!m_pGetMotorCurrent) m_DLLResultat=-2;

                VERIFY(m_pGetReduction= (PGetReduction) GetProcAddress(m_LStep4,"LSX_GetReduction"));
                if (!m_pGetReduction) m_DLLResultat=-2;

                VERIFY(m_pGetCurrentDelay= (PGetCurrentDelay) GetProcAddress(m_LStep4,"LSX_GetCurrentDelay"));
                if (!m_pGetCurrentDelay) m_DLLResultat=-2;

                VERIFY(m_pSetOutFuncLev= (PSetOutFuncLev) GetProcAddress(m_LStep4,"LSX_SetOutFuncLev"));
                if (!m_pSetOutFuncLev) m_DLLResultat=-2;

                VERIFY(m_pGetOutFuncLev= (PGetOutFuncLev) GetProcAddress(m_LStep4,"LSX_GetOutFuncLev"));
                if (!m_pGetOutFuncLev) m_DLLResultat=-2;

                VERIFY(m_pGetActiveAxes= (PGetActiveAxes) GetProcAddress(m_LStep4,"LSX_GetActiveAxes"));
                if (!m_pGetActiveAxes) m_DLLResultat=-2;

                VERIFY(m_pGetAxisDirection= (PGetAxisDirection) GetProcAddress(m_LStep4,"LSX_GetAxisDirection"));
                if (!m_pGetAxisDirection) m_DLLResultat=-2;

                VERIFY(m_pGetCalibOffset= (PGetCalibOffset) GetProcAddress(m_LStep4,"LSX_GetCalibOffset"));
                if (!m_pGetCalibOffset) m_DLLResultat=-2;

                VERIFY(m_pGetRMOffset= (PGetRMOffset) GetProcAddress(m_LStep4,"LSX_GetRMOffset"));
                if (!m_pGetRMOffset) m_DLLResultat=-2;

                VERIFY(m_pGetCalibrateDir= (PGetCalibrateDir) GetProcAddress(m_LStep4,"LSX_GetCalibrateDir"));
                if (!m_pGetCalibrateDir) m_DLLResultat=-2;

                VERIFY(m_pSetCalibBackSpeed= (PSetCalibBackSpeed) GetProcAddress(m_LStep4,"LSX_SetCalibBackSpeed"));
                if (!m_pSetCalibBackSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetCalibBackSpeed= (PGetCalibBackSpeed) GetProcAddress(m_LStep4,"LSX_GetCalibBackSpeed"));
                if (!m_pGetCalibBackSpeed) m_DLLResultat=-2;

                VERIFY(m_pSetRefSpeed= (PSetRefSpeed) GetProcAddress(m_LStep4,"LSX_SetRefSpeed"));
                if (!m_pSetRefSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetRefSpeed= (PGetRefSpeed) GetProcAddress(m_LStep4,"LSX_GetRefSpeed"));
                if (!m_pGetRefSpeed) m_DLLResultat=-2;

                VERIFY(m_pSetPowerAmplifier= (PSetPowerAmplifier) GetProcAddress(m_LStep4,"LSX_SetPowerAmplifier"));
                if (!m_pSetPowerAmplifier) m_DLLResultat=-2;

                VERIFY(m_pGetPowerAmplifier= (PGetPowerAmplifier) GetProcAddress(m_LStep4,"LSX_GetPowerAmplifier"));
                if (!m_pGetPowerAmplifier) m_DLLResultat=-2;

                VERIFY(m_pValidConfig= (PValidConfig) GetProcAddress(m_LStep4,"LSX_ValidConfig"));
                if (!m_pValidConfig) m_DLLResultat=-2;

                VERIFY(m_pValidPar= (PValidPar) GetProcAddress(m_LStep4,"LSX_ValidPar"));
                if (!m_pValidPar) m_DLLResultat=-2;

                VERIFY(m_pSetEqepConfig= (PSetEqepConfig) GetProcAddress(m_LStep4,"LSX_SetEqepConfig"));
                if (!m_pSetEqepConfig) m_DLLResultat=-2;

                VERIFY(m_pGetEqepConfig= (PGetEqepConfig) GetProcAddress(m_LStep4,"LSX_GetEqepConfig"));
                if (!m_pGetEqepConfig) m_DLLResultat=-2;

                VERIFY(m_pSetTTLOutConfig= (PSetTTLOutConfig) GetProcAddress(m_LStep4,"LSX_SetTTLOutConfig"));
                if (!m_pSetTTLOutConfig) m_DLLResultat=-2;

                VERIFY(m_pGetTTLOutConfig= (PGetTTLOutConfig) GetProcAddress(m_LStep4,"LSX_GetTTLOutConfig"));
                if (!m_pGetTTLOutConfig) m_DLLResultat=-2;

                VERIFY(m_pSetPoscon= (PSetPoscon) GetProcAddress(m_LStep4,"LSX_SetPoscon"));
                if (!m_pSetPoscon) m_DLLResultat=-2;

                VERIFY(m_pGetPoscon= (PGetPoscon) GetProcAddress(m_LStep4,"LSX_GetPoscon"));
                if (!m_pGetPoscon) m_DLLResultat=-2;

                VERIFY(m_pSetManModePreselection= (PSetManModePreselection) GetProcAddress(m_LStep4,"LSX_SetManModePreselection"));
                if (!m_pSetManModePreselection) m_DLLResultat=-2;

                VERIFY(m_pGetManModePreselection= (PGetManModePreselection) GetProcAddress(m_LStep4,"LSX_GetManModePreselection"));
                if (!m_pGetManModePreselection) m_DLLResultat=-2;

                VERIFY(m_pGetManModeLinktoAxisX= (PGetManModeLinktoAxisX) GetProcAddress(m_LStep4,"LSX_GetManModeLinktoAxisX"));
                if (!m_pGetManModeLinktoAxisX) m_DLLResultat=-2;

                VERIFY(m_pGetManModeLinktoAxisY= (PGetManModeLinktoAxisY) GetProcAddress(m_LStep4,"LSX_GetManModeLinktoAxisY"));
                if (!m_pGetManModeLinktoAxisY) m_DLLResultat=-2;

                VERIFY(m_pGetManModeLinktoAxisZ= (PGetManModeLinktoAxisZ) GetProcAddress(m_LStep4,"LSX_GetManModeLinktoAxisZ"));
                if (!m_pGetManModeLinktoAxisZ) m_DLLResultat=-2;

                VERIFY(m_pGetManModeLinktoAxisA= (PGetManModeLinktoAxisA) GetProcAddress(m_LStep4,"LSX_GetManModeLinktoAxisA"));
                if (!m_pGetManModeLinktoAxisA) m_DLLResultat=-2;

                VERIFY(m_pSetJoyRedCur= (PSetJoyRedCur) GetProcAddress(m_LStep4,"LSX_SetJoyRedCur"));
                if (!m_pSetJoyRedCur) m_DLLResultat=-2;

                VERIFY(m_pSetAnaOutPreset= (PSetAnaOutPreset) GetProcAddress(m_LStep4,"LSX_SetAnaOutPreset"));
                if (!m_pSetAnaOutPreset) m_DLLResultat=-2;

                VERIFY(m_pGetAnaOutPreset= (PGetAnaOutPreset) GetProcAddress(m_LStep4,"LSX_GetAnaOutPreset"));
                if (!m_pGetAnaOutPreset) m_DLLResultat=-2;

                VERIFY(m_pGetJoyRedCur= (PGetJoyRedCur) GetProcAddress(m_LStep4,"LSX_GetJoyRedCur"));
                if (!m_pGetJoyRedCur) m_DLLResultat=-2;

                VERIFY(m_pSetJoytoAxis= (PSetJoytoAxis) GetProcAddress(m_LStep4,"LSX_SetJoytoAxis"));
                if (!m_pSetJoytoAxis) m_DLLResultat=-2;

                VERIFY(m_pGetJoytoAxis= (PGetJoytoAxis) GetProcAddress(m_LStep4,"LSX_GetJoytoAxis"));
                if (!m_pGetJoytoAxis) m_DLLResultat=-2;

                VERIFY(m_pSetTipp= (PSetTipp) GetProcAddress(m_LStep4,"LSX_SetTipp"));
                if (!m_pSetTipp) m_DLLResultat=-2;

                VERIFY(m_pGetTipp= (PGetTipp) GetProcAddress(m_LStep4,"LSX_GetTipp"));
                if (!m_pGetTipp) m_DLLResultat=-2;

                VERIFY(m_pSetTippEnable= (PSetTippEnable) GetProcAddress(m_LStep4,"LSX_SetTippEnable"));
                if (!m_pSetTippEnable) m_DLLResultat=-2;

                VERIFY(m_pGetTippEnable= (PGetTippEnable) GetProcAddress(m_LStep4,"LSX_GetTippEnable"));
                if (!m_pGetTippEnable) m_DLLResultat=-2;

                VERIFY(m_pSetTippRedCur= (PSetTippRedCur) GetProcAddress(m_LStep4,"LSX_SetTippRedCur"));
                if (!m_pSetTippRedCur) m_DLLResultat=-2;

                VERIFY(m_pGetTippRedCur= (PGetTippRedCur) GetProcAddress(m_LStep4,"LSX_GetTippRedCur"));
                if (!m_pGetTippRedCur) m_DLLResultat=-2;

                VERIFY(m_pSetTippVel= (PSetTippVel) GetProcAddress(m_LStep4,"LSX_SetTippVel"));
                if (!m_pSetTippVel) m_DLLResultat=-2;

                VERIFY(m_pGetTippVel= (PGetTippVel) GetProcAddress(m_LStep4,"LSX_GetTippVel"));
                if (!m_pGetTippVel) m_DLLResultat=-2;

                VERIFY(m_pSetTippDir= (PSetTippDir) GetProcAddress(m_LStep4,"LSX_SetTippDir"));
                if (!m_pSetTippDir) m_DLLResultat=-2;

                VERIFY(m_pGetTippDir= (PGetTippDir) GetProcAddress(m_LStep4,"LSX_GetTippDir"));
                if (!m_pGetTippDir) m_DLLResultat=-2;

                VERIFY(m_pSetModulo= (PSetModulo) GetProcAddress(m_LStep4,"LSX_SetModulo"));
                if (!m_pSetModulo) m_DLLResultat=-2;

                VERIFY(m_pGetModulo= (PGetModulo) GetProcAddress(m_LStep4,"LSX_GetModulo"));
                if (!m_pGetModulo) m_DLLResultat=-2;

                VERIFY(m_pSetModuloMode= (PSetModuloMode) GetProcAddress(m_LStep4,"LSX_SetModuloMode"));
                if (!m_pSetModuloMode) m_DLLResultat=-2;

                VERIFY(m_pGetModuloMode= (PGetModuloMode) GetProcAddress(m_LStep4,"LSX_GetModuloMode"));
                if (!m_pGetModuloMode) m_DLLResultat=-2;

                VERIFY(m_pSetEncDir= (PSetEncDir) GetProcAddress(m_LStep4,"LSX_SetEncDir"));
                if (!m_pSetEncDir) m_DLLResultat=-2;

                VERIFY(m_pGetEncDir= (PGetEncDir) GetProcAddress(m_LStep4,"LSX_GetEncDir"));
                if (!m_pGetEncDir) m_DLLResultat=-2;

                VERIFY(m_pSetEncPolePairs= (PSetEncPolePairs) GetProcAddress(m_LStep4,"LSX_SetEncPolePairs"));
                if (!m_pSetEncPolePairs) m_DLLResultat=-2;

                VERIFY(m_pGetEncPolePairs= (PGetEncPolePairs) GetProcAddress(m_LStep4,"LSX_GetEncPolePairs"));
                if (!m_pGetEncPolePairs) m_DLLResultat=-2;

                VERIFY(m_pSetEnctoAxis= (PSetEnctoAxis) GetProcAddress(m_LStep4,"LSX_SetEnctoAxis"));
                if (!m_pSetEnctoAxis) m_DLLResultat=-2;

                VERIFY(m_pGetEnctoAxis= (PGetEnctoAxis) GetProcAddress(m_LStep4,"LSX_GetEnctoAxis"));
                if (!m_pGetEnctoAxis) m_DLLResultat=-2;

                VERIFY(m_pSetEncType= (PSetEncType) GetProcAddress(m_LStep4,"LSX_SetEncType"));
                if (!m_pSetEncType) m_DLLResultat=-2;

                VERIFY(m_pGetEncType= (PGetEncType) GetProcAddress(m_LStep4,"LSX_GetEncType"));
                if (!m_pGetEncType) m_DLLResultat=-2;

                VERIFY(m_pSetMotortempSensor= (PSetMotortempSensor) GetProcAddress(m_LStep4,"LSX_SetMotortempSensor"));
                if (!m_pSetMotortempSensor) m_DLLResultat=-2;

                VERIFY(m_pGetMotortempSensor= (PGetMotortempSensor) GetProcAddress(m_LStep4,"LSX_GetMotortempSensor"));
                if (!m_pGetMotortempSensor) m_DLLResultat=-2;

                VERIFY(m_pSetMotortempSensormin= (PSetMotortempSensormin) GetProcAddress(m_LStep4,"LSX_SetMotortempSensormin"));
                if (!m_pSetMotortempSensormin) m_DLLResultat=-2;

                VERIFY(m_pGetMotortempSensormin= (PGetMotortempSensormin) GetProcAddress(m_LStep4,"LSX_GetMotortempSensormin"));
                if (!m_pGetMotortempSensormin) m_DLLResultat=-2;

                VERIFY(m_pSetMotortempSensormax= (PSetMotortempSensormax) GetProcAddress(m_LStep4,"LSX_SetMotortempSensormax"));
                if (!m_pSetMotortempSensormax) m_DLLResultat=-2;

                VERIFY(m_pGetMotortempSensormax= (PGetMotortempSensormax) GetProcAddress(m_LStep4,"LSX_GetMotortempSensormax"));
                if (!m_pGetMotortempSensormax) m_DLLResultat=-2;

                VERIFY(m_pGetMotortempSensorValue= (PGetMotortempSensorValue) GetProcAddress(m_LStep4,"LSX_GetMotortempSensorValue"));
                if (!m_pGetMotortempSensorValue) m_DLLResultat=-2;

                VERIFY(m_pSetKommMode= (PSetKommMode) GetProcAddress(m_LStep4,"LSX_SetKommMode"));
                if (!m_pSetKommMode) m_DLLResultat=-2;

                VERIFY(m_pGetKommMode= (PGetKommMode) GetProcAddress(m_LStep4,"LSX_GetKommMode"));
                if (!m_pGetKommMode) m_DLLResultat=-2;

                VERIFY(m_pSetKommEncDir= (PSetKommEncDir) GetProcAddress(m_LStep4,"LSX_SetKommEncDir"));
                if (!m_pSetKommEncDir) m_DLLResultat=-2;

                VERIFY(m_pGetKommEncDir= (PGetKommEncDir) GetProcAddress(m_LStep4,"LSX_GetKommEncDir"));
                if (!m_pGetKommEncDir) m_DLLResultat=-2;

                VERIFY(m_pSetKommEncPolePairs= (PSetKommEncPolePairs) GetProcAddress(m_LStep4,"LSX_SetKommEncPolePairs"));
                if (!m_pSetKommEncPolePairs) m_DLLResultat=-2;

                VERIFY(m_pGetKommEncPolePairs= (PGetKommEncPolePairs) GetProcAddress(m_LStep4,"LSX_GetKommEncPolePairs"));
                if (!m_pGetKommEncPolePairs) m_DLLResultat=-2;

                VERIFY(m_pSetKommEnctoAxis= (PSetKommEnctoAxis) GetProcAddress(m_LStep4,"LSX_SetKommEnctoAxis"));
                if (!m_pSetKommEnctoAxis) m_DLLResultat=-2;

                VERIFY(m_pGetKommEnctoAxis= (PGetKommEnctoAxis) GetProcAddress(m_LStep4,"LSX_GetKommEnctoAxis"));
                if (!m_pGetKommEnctoAxis) m_DLLResultat=-2;

                VERIFY(m_pSetKommEncType= (PSetKommEncType) GetProcAddress(m_LStep4,"LSX_SetKommEncType"));
                if (!m_pSetKommEncType) m_DLLResultat=-2;

                VERIFY(m_pGetKommEncType= (PGetKommEncType) GetProcAddress(m_LStep4,"LSX_GetKommEncType"));
                if (!m_pGetKommEncType) m_DLLResultat=-2;

                VERIFY(m_pSetMotorPolePairs= (PSetMotorPolePairs) GetProcAddress(m_LStep4,"LSX_SetMotorPolePairs"));
                if (!m_pSetMotorPolePairs) m_DLLResultat=-2;

                VERIFY(m_pGetMotorPolePairs= (PGetMotorPolePairs) GetProcAddress(m_LStep4,"LSX_GetMotorPolePairs"));
                if (!m_pGetMotorPolePairs) m_DLLResultat=-2;

                VERIFY(m_pSetMotorPolePairRes= (PSetMotorPolePairRes) GetProcAddress(m_LStep4,"LSX_SetMotorPolePairRes"));
                if (!m_pSetMotorPolePairRes) m_DLLResultat=-2;

                VERIFY(m_pGetMotorPolePairRes= (PGetMotorPolePairRes) GetProcAddress(m_LStep4,"LSX_GetMotorPolePairRes"));
                if (!m_pGetMotorPolePairRes) m_DLLResultat=-2;

                VERIFY(m_pSetMotorPoleScale= (PSetMotorPoleScale) GetProcAddress(m_LStep4,"LSX_SetMotorPoleScale"));
                if (!m_pSetMotorPoleScale) m_DLLResultat=-2;

                VERIFY(m_pGetMotorPoleScale= (PGetMotorPoleScale) GetProcAddress(m_LStep4,"LSX_GetMotorPoleScale"));
                if (!m_pGetMotorPoleScale) m_DLLResultat=-2;

                VERIFY(m_pGetSysStat= (PGetSysStat) GetProcAddress(m_LStep4,"LSX_GetSysStat"));
                if (!m_pGetSysStat) m_DLLResultat=-2;

                VERIFY(m_pGetSysStatusW= (PGetSysStatusW) GetProcAddress(m_LStep4,"LSX_GetSysStatusW"));
                if (!m_pGetSysStatusW) m_DLLResultat=-2;

                VERIFY(m_pGetSysStatus= (PGetSysStatus) GetProcAddress(m_LStep4,"LSX_GetSysStatus"));
                if (!m_pGetSysStatus) m_DLLResultat=-2;

                VERIFY(m_pGetStopStatus= (PGetStopStatus) GetProcAddress(m_LStep4,"LSX_GetStopStatus"));
                if (!m_pGetStopStatus) m_DLLResultat=-2;

                VERIFY(m_pQuit= (PQuit) GetProcAddress(m_LStep4,"LSX_Quit"));
                if (!m_pQuit) m_DLLResultat=-2;

                VERIFY(m_pSetMotorBrakeSwitchOnDelay= (PSetMotorBrakeSwitchOnDelay) GetProcAddress(m_LStep4,"LSX_SetMotorBrakeSwitchOnDelay"));
                if (!m_pSetMotorBrakeSwitchOnDelay) m_DLLResultat=-2;

                VERIFY(m_pGetMotorBrakeSwitchOnDelay= (PGetMotorBrakeSwitchOnDelay) GetProcAddress(m_LStep4,"LSX_GetMotorBrakeSwitchOnDelay"));
                if (!m_pGetMotorBrakeSwitchOnDelay) m_DLLResultat=-2;

                VERIFY(m_pSetMotorBrakeSwitchOffDelay= (PSetMotorBrakeSwitchOffDelay) GetProcAddress(m_LStep4,"LSX_SetMotorBrakeSwitchOffDelay"));
                if (!m_pSetMotorBrakeSwitchOffDelay) m_DLLResultat=-2;

                VERIFY(m_pGetMotorBrakeSwitchOffDelay= (PGetMotorBrakeSwitchOffDelay) GetProcAddress(m_LStep4,"LSX_GetMotorBrakeSwitchOffDelay"));
                if (!m_pGetMotorBrakeSwitchOffDelay) m_DLLResultat=-2;

                VERIFY(m_pSetMotorAutoKommDelay= (PSetMotorAutoKommDelay) GetProcAddress(m_LStep4,"LSX_SetMotorAutoKommDelay"));
                if (!m_pSetMotorAutoKommDelay) m_DLLResultat=-2;

                VERIFY(m_pGetMotorAutoKommDelay= (PGetMotorAutoKommDelay) GetProcAddress(m_LStep4,"LSX_GetMotorAutoKommDelay"));
                if (!m_pGetMotorAutoKommDelay) m_DLLResultat=-2;

                VERIFY(m_pSetMotorAutoKommSpeedScale= (PSetMotorAutoKommSpeedScale) GetProcAddress(m_LStep4,"LSX_SetMotorAutoKommSpeedScale"));
                if (!m_pSetMotorAutoKommSpeedScale) m_DLLResultat=-2;

                VERIFY(m_pGetMotorAutoKommSpeedScale= (PGetMotorAutoKommSpeedScale) GetProcAddress(m_LStep4,"LSX_GetMotorAutoKommSpeedScale"));
                if (!m_pGetMotorAutoKommSpeedScale) m_DLLResultat=-2;

                VERIFY(m_pSetMotorForceConstant= (PSetMotorForceConstant) GetProcAddress(m_LStep4,"LSX_SetMotorForceConstant"));
                if (!m_pSetMotorForceConstant) m_DLLResultat=-2;

                VERIFY(m_pGetMotorForceConstant= (PGetMotorForceConstant) GetProcAddress(m_LStep4,"LSX_GetMotorForceConstant"));
                if (!m_pGetMotorForceConstant) m_DLLResultat=-2;

                VERIFY(m_pSetMotorLoad= (PSetMotorLoad) GetProcAddress(m_LStep4,"LSX_SetMotorLoad"));
                if (!m_pSetMotorLoad) m_DLLResultat=-2;

                VERIFY(m_pGetMotorLoad= (PGetMotorLoad) GetProcAddress(m_LStep4,"LSX_GetMotorLoad"));
                if (!m_pGetMotorLoad) m_DLLResultat=-2;

                VERIFY(m_pSetMotorMomentConstant= (PSetMotorMomentConstant) GetProcAddress(m_LStep4,"LSX_SetMotorMomentConstant"));
                if (!m_pSetMotorMomentConstant) m_DLLResultat=-2;

                VERIFY(m_pGetMotorMomentConstant= (PGetMotorMomentConstant) GetProcAddress(m_LStep4,"LSX_GetMotorMomentConstant"));
                if (!m_pGetMotorMomentConstant) m_DLLResultat=-2;

                VERIFY(m_pSetMotorMomentOfInertia= (PSetMotorMomentOfInertia) GetProcAddress(m_LStep4,"LSX_SetMotorMomentOfInertia"));
                if (!m_pSetMotorMomentOfInertia) m_DLLResultat=-2;

                VERIFY(m_pGetMotorMomentOfInertia= (PGetMotorMomentOfInertia) GetProcAddress(m_LStep4,"LSX_GetMotorMomentOfInertia"));
                if (!m_pGetMotorMomentOfInertia) m_DLLResultat=-2;

                VERIFY(m_pSetPosConKP= (PSetPosConKP) GetProcAddress(m_LStep4,"LSX_SetPosConKP"));
                if (!m_pSetPosConKP) m_DLLResultat=-2;

                VERIFY(m_pGetPosConKP= (PGetPosConKP) GetProcAddress(m_LStep4,"LSX_GetPosConKP"));
                if (!m_pGetPosConKP) m_DLLResultat=-2;

                VERIFY(m_pSetPosConAdaptiveKP= (PSetPosConAdaptiveKP) GetProcAddress(m_LStep4,"LSX_SetPosConAdaptiveKP"));
                if (!m_pSetPosConAdaptiveKP) m_DLLResultat=-2;

                VERIFY(m_pGetPosConAdaptiveKP= (PGetPosConAdaptiveKP) GetProcAddress(m_LStep4,"LSX_GetPosConAdaptiveKP"));
                if (!m_pGetPosConAdaptiveKP) m_DLLResultat=-2;

                VERIFY(m_pSetPosConKI= (PSetPosConKI) GetProcAddress(m_LStep4,"LSX_SetPosConKI"));
                if (!m_pSetPosConKI) m_DLLResultat=-2;

                VERIFY(m_pGetPosConKI= (PGetPosConKI) GetProcAddress(m_LStep4,"LSX_GetPosConKI"));
                if (!m_pGetPosConKI) m_DLLResultat=-2;

                VERIFY(m_pSetPosConAdaptiveKI= (PSetPosConAdaptiveKI) GetProcAddress(m_LStep4,"LSX_SetPosConAdaptiveKI"));
                if (!m_pSetPosConAdaptiveKI) m_DLLResultat=-2;

                VERIFY(m_pGetPosConAdaptiveKI= (PGetPosConAdaptiveKI) GetProcAddress(m_LStep4,"LSX_GetPosConAdaptiveKI"));
                if (!m_pGetPosConAdaptiveKI) m_DLLResultat=-2;

                VERIFY(m_pSetPosConOutPass= (PSetPosConOutPass) GetProcAddress(m_LStep4,"LSX_SetPosConOutPass"));
                if (!m_pSetPosConOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetPosConOutPass= (PGetPosConOutPass) GetProcAddress(m_LStep4,"LSX_GetPosConOutPass"));
                if (!m_pGetPosConOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetPosConAdaptiveOutPass= (PSetPosConAdaptiveOutPass) GetProcAddress(m_LStep4,"LSX_SetPosConAdaptiveOutPass"));
                if (!m_pSetPosConAdaptiveOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetPosConAdaptiveOutPass= (PGetPosConAdaptiveOutPass) GetProcAddress(m_LStep4,"LSX_GetPosConAdaptiveOutPass"));
                if (!m_pGetPosConAdaptiveOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetPosConEnable= (PSetPosConEnable) GetProcAddress(m_LStep4,"LSX_SetPosConEnable"));
                if (!m_pSetPosConEnable) m_DLLResultat=-2;

                VERIFY(m_pGetPosConEnable= (PGetPosConEnable) GetProcAddress(m_LStep4,"LSX_GetPosConEnable"));
                if (!m_pGetPosConEnable) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedConKP= (PSetSpeedConKP) GetProcAddress(m_LStep4,"LSX_SetSpeedConKP"));
                if (!m_pSetSpeedConKP) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedConKP= (PGetSpeedConKP) GetProcAddress(m_LStep4,"LSX_GetSpeedConKP"));
                if (!m_pGetSpeedConKP) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedConKI= (PSetSpeedConKI) GetProcAddress(m_LStep4,"LSX_SetSpeedConKI"));
                if (!m_pSetSpeedConKI) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedConKI= (PGetSpeedConKI) GetProcAddress(m_LStep4,"LSX_GetSpeedConKI"));
                if (!m_pGetSpeedConKI) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedConKD= (PSetSpeedConKD) GetProcAddress(m_LStep4,"LSX_SetSpeedConKD"));
                if (!m_pSetSpeedConKD) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedConKD= (PGetSpeedConKD) GetProcAddress(m_LStep4,"LSX_GetSpeedConKD"));
                if (!m_pGetSpeedConKD) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedConOutPass= (PSetSpeedConOutPass) GetProcAddress(m_LStep4,"LSX_SetSpeedConOutPass"));
                if (!m_pSetSpeedConOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedConOutPass= (PGetSpeedConOutPass) GetProcAddress(m_LStep4,"LSX_GetSpeedConOutPass"));
                if (!m_pGetSpeedConOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetPosConNominalSpeed= (PSetPosConNominalSpeed) GetProcAddress(m_LStep4,"LSX_SetPosConNominalSpeed"));
                if (!m_pSetPosConNominalSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetPosConNominalSpeed= (PGetPosConNominalSpeed) GetProcAddress(m_LStep4,"LSX_GetPosConNominalSpeed"));
                if (!m_pGetPosConNominalSpeed) m_DLLResultat=-2;

                VERIFY(m_pSetPosConAdaptiveSpeed= (PSetPosConAdaptiveSpeed) GetProcAddress(m_LStep4,"LSX_SetPosConAdaptiveSpeed"));
                if (!m_pSetPosConAdaptiveSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetPosConAdaptiveSpeed= (PGetPosConAdaptiveSpeed) GetProcAddress(m_LStep4,"LSX_GetPosConAdaptiveSpeed"));
                if (!m_pGetPosConAdaptiveSpeed) m_DLLResultat=-2;

                VERIFY(m_pSetActSpeedFilterConst= (PSetActSpeedFilterConst) GetProcAddress(m_LStep4,"LSX_SetActSpeedFilterConst"));
                if (!m_pSetActSpeedFilterConst) m_DLLResultat=-2;

                VERIFY(m_pGetActSpeedFilterConst= (PGetActSpeedFilterConst) GetProcAddress(m_LStep4,"LSX_GetActSpeedFilterConst"));
                if (!m_pGetActSpeedFilterConst) m_DLLResultat=-2;

                VERIFY(m_pSetSpeedFeedForward= (PSetSpeedFeedForward) GetProcAddress(m_LStep4,"LSX_SetSpeedFeedForward"));
                if (!m_pSetSpeedFeedForward) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedFeedForward= (PGetSpeedFeedForward) GetProcAddress(m_LStep4,"LSX_GetSpeedFeedForward"));
                if (!m_pGetSpeedFeedForward) m_DLLResultat=-2;

                VERIFY(m_pSetActAccelFilterConst= (PSetActAccelFilterConst) GetProcAddress(m_LStep4,"LSX_SetActAccelFilterConst"));
                if (!m_pSetActAccelFilterConst) m_DLLResultat=-2;

                VERIFY(m_pGetActAccelFilterConst= (PGetActAccelFilterConst) GetProcAddress(m_LStep4,"LSX_GetActAccelFilterConst"));
                if (!m_pGetActAccelFilterConst) m_DLLResultat=-2;

                VERIFY(m_pSetAccelFeedForward= (PSetAccelFeedForward) GetProcAddress(m_LStep4,"LSX_SetAccelFeedForward"));
                if (!m_pSetAccelFeedForward) m_DLLResultat=-2;

                VERIFY(m_pGetAccelFeedForward= (PGetAccelFeedForward) GetProcAddress(m_LStep4,"LSX_GetAccelFeedForward"));
                if (!m_pGetAccelFeedForward) m_DLLResultat=-2;

                VERIFY(m_pSetAccelFeedForwardOutPass= (PSetAccelFeedForwardOutPass) GetProcAddress(m_LStep4,"LSX_SetAccelFeedForwardOutPass"));
                if (!m_pSetAccelFeedForwardOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetAccelFeedForwardOutPass= (PGetAccelFeedForwardOutPass) GetProcAddress(m_LStep4,"LSX_GetAccelFeedForwardOutPass"));
                if (!m_pGetAccelFeedForwardOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetPosMode= (PSetPosMode) GetProcAddress(m_LStep4,"LSX_SetPosMode"));
                if (!m_pSetPosMode) m_DLLResultat=-2;

                VERIFY(m_pGetPosMode= (PGetPosMode) GetProcAddress(m_LStep4,"LSX_GetPosMode"));
                if (!m_pGetPosMode) m_DLLResultat=-2;

                VERIFY(m_pGetSpeedConTN= (PGetSpeedConTN) GetProcAddress(m_LStep4,"LSX_GetSpeedConTN"));
                if (!m_pGetSpeedConTN) m_DLLResultat=-2;

                VERIFY(m_pGetPowerAmplifierStatus= (PGetPowerAmplifierStatus) GetProcAddress(m_LStep4,"LSX_GetPowerAmplifierStatus"));
                if (!m_pGetPowerAmplifierStatus) m_DLLResultat=-2;

                VERIFY(m_pGetPTemp= (PGetPTemp) GetProcAddress(m_LStep4,"LSX_GetPTemp"));
                if (!m_pGetPTemp) m_DLLResultat=-2;

                VERIFY(m_pSetSysSampleRate= (PSetSysSampleRate) GetProcAddress(m_LStep4,"LSX_SetSysSampleRate"));
                if (!m_pSetSysSampleRate) m_DLLResultat=-2;

                VERIFY(m_pGetSysSampleRate= (PGetSysSampleRate) GetProcAddress(m_LStep4,"LSX_GetSysSampleRate"));
                if (!m_pGetSysSampleRate) m_DLLResultat=-2;

                VERIFY(m_pSetAxisMap= (PSetAxisMap) GetProcAddress(m_LStep4,"LSX_SetAxisMap"));
                if (!m_pSetAxisMap) m_DLLResultat=-2;

                VERIFY(m_pGetAxisMap= (PGetAxisMap) GetProcAddress(m_LStep4,"LSX_GetAxisMap"));
                if (!m_pGetAxisMap) m_DLLResultat=-2;

                VERIFY(m_pSetBaud= (PSetBaud) GetProcAddress(m_LStep4,"LSX_SetBaud"));
                if (!m_pSetBaud) m_DLLResultat=-2;

                VERIFY(m_pGetBaud= (PGetBaud) GetProcAddress(m_LStep4,"LSX_GetBaud"));
                if (!m_pGetBaud) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_Two= (PSetTrigger_Two) GetProcAddress(m_LStep4,"LSX_SetTrigger_Two"));
                if (!m_pSetTrigger_Two) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_Two= (PGetTrigger_Two) GetProcAddress(m_LStep4,"LSX_GetTrigger_Two"));
                if (!m_pGetTrigger_Two) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerDim= (PSetTriggerDim) GetProcAddress(m_LStep4,"LSX_SetTriggerDim"));
                if (!m_pSetTriggerDim) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerDim= (PGetTriggerDim) GetProcAddress(m_LStep4,"LSX_GetTriggerDim"));
                if (!m_pGetTriggerDim) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoDim= (PSetTrigger_TwoDim) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoDim"));
                if (!m_pSetTrigger_TwoDim) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoDim= (PGetTrigger_TwoDim) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoDim"));
                if (!m_pGetTrigger_TwoDim) m_DLLResultat=-2;

                VERIFY(m_pSetPosWindowRange= (PSetPosWindowRange) GetProcAddress(m_LStep4,"LSX_SetPosWindowRange"));
                if (!m_pSetPosWindowRange) m_DLLResultat=-2;

                VERIFY(m_pGetPosWindowRange= (PGetPosWindowRange) GetProcAddress(m_LStep4,"LSX_GetPosWindowRange"));
                if (!m_pGetPosWindowRange) m_DLLResultat=-2;

                VERIFY(m_pSetPosWindowTime= (PSetPosWindowTime) GetProcAddress(m_LStep4,"LSX_SetPosWindowTime"));
                if (!m_pSetPosWindowTime) m_DLLResultat=-2;

                VERIFY(m_pGetPosWindowTime= (PGetPosWindowTime) GetProcAddress(m_LStep4,"LSX_GetPosWindowTime"));
                if (!m_pGetPosWindowTime) m_DLLResultat=-2;

                VERIFY(m_pSetPosWindowTimeout= (PSetPosWindowTimeout) GetProcAddress(m_LStep4,"LSX_SetPosWindowTimeout"));
                if (!m_pSetPosWindowTimeout) m_DLLResultat=-2;

                VERIFY(m_pGetPosWindowTimeout= (PGetPosWindowTimeout) GetProcAddress(m_LStep4,"LSX_GetPosWindowTimeout"));
                if (!m_pGetPosWindowTimeout) m_DLLResultat=-2;

                VERIFY(m_pSetPosWindowCheck= (PSetPosWindowCheck) GetProcAddress(m_LStep4,"LSX_SetPosWindowCheck"));
                if (!m_pSetPosWindowCheck) m_DLLResultat=-2;

                VERIFY(m_pGetPosWindowCheck= (PGetPosWindowCheck) GetProcAddress(m_LStep4,"LSX_GetPosWindowCheck"));
                if (!m_pGetPosWindowCheck) m_DLLResultat=-2;

                VERIFY(m_pSetDeviationRange= (PSetDeviationRange) GetProcAddress(m_LStep4,"LSX_SetDeviationRange"));
                if (!m_pSetDeviationRange) m_DLLResultat=-2;

                VERIFY(m_pGetDeviationRange= (PGetDeviationRange) GetProcAddress(m_LStep4,"LSX_GetDeviationRange"));
                if (!m_pGetDeviationRange) m_DLLResultat=-2;

                VERIFY(m_pSetDeviationTime= (PSetDeviationTime) GetProcAddress(m_LStep4,"LSX_SetDeviationTime"));
                if (!m_pSetDeviationTime) m_DLLResultat=-2;

                VERIFY(m_pGetDeviationTime= (PGetDeviationTime) GetProcAddress(m_LStep4,"LSX_GetDeviationTime"));
                if (!m_pGetDeviationTime) m_DLLResultat=-2;

                VERIFY(m_pSetDeviationCheck= (PSetDeviationCheck) GetProcAddress(m_LStep4,"LSX_SetDeviationCheck"));
                if (!m_pSetDeviationCheck) m_DLLResultat=-2;

                VERIFY(m_pGetDeviationCheck= (PGetDeviationCheck) GetProcAddress(m_LStep4,"LSX_GetDeviationCheck"));
                if (!m_pGetDeviationCheck) m_DLLResultat=-2;

                VERIFY(m_pSetHalt= (PSetHalt) GetProcAddress(m_LStep4,"LSX_SetHalt"));
                if (!m_pSetHalt) m_DLLResultat=-2;

                VERIFY(m_pSetMotorTablePatch= (PSetMotorTablePatch) GetProcAddress(m_LStep4,"LSX_SetMotorTablePatch"));
                if (!m_pSetMotorTablePatch) m_DLLResultat=-2;

                VERIFY(m_pGetMotorTablePatch= (PGetMotorTablePatch) GetProcAddress(m_LStep4,"LSX_GetMotorTablePatch"));
                if (!m_pGetMotorTablePatch) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickFilter= (PSetJoystickFilter) GetProcAddress(m_LStep4,"LSX_SetJoystickFilter"));
                if (!m_pSetJoystickFilter) m_DLLResultat=-2;

                VERIFY(m_pGetJoystickFilter= (PGetJoystickFilter) GetProcAddress(m_LStep4,"LSX_GetJoystickFilter"));
                if (!m_pGetJoystickFilter) m_DLLResultat=-2;

                VERIFY(m_pSetStopPolarity= (PSetStopPolarity) GetProcAddress(m_LStep4,"LSX_SetStopPolarity"));
                if (!m_pSetStopPolarity) m_DLLResultat=-2;

                VERIFY(m_pGetStopPolarity= (PGetStopPolarity) GetProcAddress(m_LStep4,"LSX_GetStopPolarity"));
                if (!m_pGetStopPolarity) m_DLLResultat=-2;

                VERIFY(m_pSetVLevel= (PSetVLevel) GetProcAddress(m_LStep4,"LSX_SetVLevel"));
                if (!m_pSetVLevel) m_DLLResultat=-2;

                VERIFY(m_pGetVLevel= (PGetVLevel) GetProcAddress(m_LStep4,"LSX_GetVLevel"));
                if (!m_pGetVLevel) m_DLLResultat=-2;

                VERIFY(m_pSetStopAccel= (PSetStopAccel) GetProcAddress(m_LStep4,"LSX_SetStopAccel"));
                if (!m_pSetStopAccel) m_DLLResultat=-2;

                VERIFY(m_pGetStopAccel= (PGetStopAccel) GetProcAddress(m_LStep4,"LSX_GetStopAccel"));
                if (!m_pGetStopAccel) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStrInfo= (PGetVersionStrInfo) GetProcAddress(m_LStep4,"LSX_GetVersionStrInfo"));
                if (!m_pGetVersionStrInfo) m_DLLResultat=-2;

                VERIFY(m_pGetVersionStrInfoW= (PGetVersionStrInfoW) GetProcAddress(m_LStep4,"LSX_GetVersionStrInfoW"));
                if (!m_pGetVersionStrInfoW) m_DLLResultat=-2;

                VERIFY(m_pGetStatusLimit= (PGetStatusLimit) GetProcAddress(m_LStep4,"LSX_GetStatusLimit"));
                if (!m_pGetStatusLimit) m_DLLResultat=-2;

                VERIFY(m_pGetStatusLimitW= (PGetStatusLimitW) GetProcAddress(m_LStep4,"LSX_GetStatusLimitW"));
                if (!m_pGetStatusLimitW) m_DLLResultat=-2;

                VERIFY(m_pGetSecurityErr= (PGetSecurityErr) GetProcAddress(m_LStep4,"LSX_GetSecurityErr"));
                if (!m_pGetSecurityErr) m_DLLResultat=-2;

                VERIFY(m_pGetSecurityStatus= (PGetSecurityStatus) GetProcAddress(m_LStep4,"LSX_GetSecurityStatus"));
                if (!m_pGetSecurityStatus) m_DLLResultat=-2;

                VERIFY(m_pGetDelay= (PGetDelay) GetProcAddress(m_LStep4,"LSX_GetDelay"));
                if (!m_pGetDelay) m_DLLResultat=-2;

                VERIFY(m_pGetDistance= (PGetDistance) GetProcAddress(m_LStep4,"LSX_GetDistance"));
                if (!m_pGetDistance) m_DLLResultat=-2;

                VERIFY(m_pClearPos= (PClearPos) GetProcAddress(m_LStep4,"LSX_ClearPos"));
                if (!m_pClearPos) m_DLLResultat=-2;

                VERIFY(m_pSetDigJoySpeed= (PSetDigJoySpeed) GetProcAddress(m_LStep4,"LSX_SetDigJoySpeed"));
                if (!m_pSetDigJoySpeed) m_DLLResultat=-2;

                VERIFY(m_pGetDigJoySpeed= (PGetDigJoySpeed) GetProcAddress(m_LStep4,"LSX_GetDigJoySpeed"));
                if (!m_pGetDigJoySpeed) m_DLLResultat=-2;

                VERIFY(m_pGetJoystickDir= (PGetJoystickDir) GetProcAddress(m_LStep4,"LSX_GetJoystickDir"));
                if (!m_pGetJoystickDir) m_DLLResultat=-2;

                VERIFY(m_pGetJoystick= (PGetJoystick) GetProcAddress(m_LStep4,"LSX_GetJoystick"));
                if (!m_pGetJoystick) m_DLLResultat=-2;

                VERIFY(m_pGetJoystickWindow= (PGetJoystickWindow) GetProcAddress(m_LStep4,"LSX_GetJoystickWindow"));
                if (!m_pGetJoystickWindow) m_DLLResultat=-2;

                VERIFY(m_pGetHandWheel= (PGetHandWheel) GetProcAddress(m_LStep4,"LSX_GetHandWheel"));
                if (!m_pGetHandWheel) m_DLLResultat=-2;

                VERIFY(m_pGetBPZ= (PGetBPZ) GetProcAddress(m_LStep4,"LSX_GetBPZ"));
                if (!m_pGetBPZ) m_DLLResultat=-2;

                VERIFY(m_pGetBPZTrackballFactor= (PGetBPZTrackballFactor) GetProcAddress(m_LStep4,"LSX_GetBPZTrackballFactor"));
                if (!m_pGetBPZTrackballFactor) m_DLLResultat=-2;

                VERIFY(m_pGetBPZTrackballBackLash= (PGetBPZTrackballBackLash) GetProcAddress(m_LStep4,"LSX_GetBPZTrackballBackLash"));
                if (!m_pGetBPZTrackballBackLash) m_DLLResultat=-2;

                VERIFY(m_pGetBPZJoyspeed= (PGetBPZJoyspeed) GetProcAddress(m_LStep4,"LSX_GetBPZJoyspeed"));
                if (!m_pGetBPZJoyspeed) m_DLLResultat=-2;

                VERIFY(m_pGetLimitControl= (PGetLimitControl) GetProcAddress(m_LStep4,"LSX_GetLimitControl"));
                if (!m_pGetLimitControl) m_DLLResultat=-2;

                VERIFY(m_pSetAutoLimitAfterCalibRM= (PSetAutoLimitAfterCalibRM) GetProcAddress(m_LStep4,"LSX_SetAutoLimitAfterCalibRM"));
                if (!m_pSetAutoLimitAfterCalibRM) m_DLLResultat=-2;

                VERIFY(m_pGetAutoLimitAfterCalibRM= (PGetAutoLimitAfterCalibRM) GetProcAddress(m_LStep4,"LSX_GetAutoLimitAfterCalibRM"));
                if (!m_pGetAutoLimitAfterCalibRM) m_DLLResultat=-2;

                VERIFY(m_pGetSwitchPolarity= (PGetSwitchPolarity) GetProcAddress(m_LStep4,"LSX_GetSwitchPolarity"));
                if (!m_pGetSwitchPolarity) m_DLLResultat=-2;

                VERIFY(m_pGetSwitchActive= (PGetSwitchActive) GetProcAddress(m_LStep4,"LSX_GetSwitchActive"));
                if (!m_pGetSwitchActive) m_DLLResultat=-2;

                VERIFY(m_pGetTVRMode= (PGetTVRMode) GetProcAddress(m_LStep4,"LSX_GetTVRMode"));
                if (!m_pGetTVRMode) m_DLLResultat=-2;

                VERIFY(m_pGetFactorTVR= (PGetFactorTVR) GetProcAddress(m_LStep4,"LSX_GetFactorTVR"));
                if (!m_pGetFactorTVR) m_DLLResultat=-2;

                VERIFY(m_pSetTVROutMode= (PSetTVROutMode) GetProcAddress(m_LStep4,"LSX_SetTVROutMode"));
                if (!m_pSetTVROutMode) m_DLLResultat=-2;

                VERIFY(m_pGetTVROutMode= (PGetTVROutMode) GetProcAddress(m_LStep4,"LSX_GetTVROutMode"));
                if (!m_pGetTVROutMode) m_DLLResultat=-2;

                VERIFY(m_pSetTVROutResolution= (PSetTVROutResolution) GetProcAddress(m_LStep4,"LSX_SetTVROutResolution"));
                if (!m_pSetTVROutResolution) m_DLLResultat=-2;

                VERIFY(m_pGetTVROutResolution= (PGetTVROutResolution) GetProcAddress(m_LStep4,"LSX_GetTVROutResolution"));
                if (!m_pGetTVROutResolution) m_DLLResultat=-2;

                VERIFY(m_pSetTVROutPitch= (PSetTVROutPitch) GetProcAddress(m_LStep4,"LSX_SetTVROutPitch"));
                if (!m_pSetTVROutPitch) m_DLLResultat=-2;

                VERIFY(m_pGetTVROutPitch= (PGetTVROutPitch) GetProcAddress(m_LStep4,"LSX_GetTVROutPitch"));
                if (!m_pGetTVROutPitch) m_DLLResultat=-2;

                VERIFY(m_pSetVelTVRO= (PSetVelTVRO) GetProcAddress(m_LStep4,"LSX_SetVelTVRO"));
                if (!m_pSetVelTVRO) m_DLLResultat=-2;

                VERIFY(m_pGetVelTVRO= (PGetVelTVRO) GetProcAddress(m_LStep4,"LSX_GetVelTVRO"));
                if (!m_pGetVelTVRO) m_DLLResultat=-2;

                VERIFY(m_pSetAccelTVRO= (PSetAccelTVRO) GetProcAddress(m_LStep4,"LSX_SetAccelTVRO"));
                if (!m_pSetAccelTVRO) m_DLLResultat=-2;

                VERIFY(m_pGetAccelTVRO= (PGetAccelTVRO) GetProcAddress(m_LStep4,"LSX_GetAccelTVRO"));
                if (!m_pGetAccelTVRO) m_DLLResultat=-2;

                VERIFY(m_pSetVelSingleAxisTVRO= (PSetVelSingleAxisTVRO) GetProcAddress(m_LStep4,"LSX_SetVelSingleAxisTVRO"));
                if (!m_pSetVelSingleAxisTVRO) m_DLLResultat=-2;

                VERIFY(m_pSetAccelSingleAxisTVRO= (PSetAccelSingleAxisTVRO) GetProcAddress(m_LStep4,"LSX_SetAccelSingleAxisTVRO"));
                if (!m_pSetAccelSingleAxisTVRO) m_DLLResultat=-2;

                VERIFY(m_pSetPosTVRO= (PSetPosTVRO) GetProcAddress(m_LStep4,"LSX_SetPosTVRO"));
                if (!m_pSetPosTVRO) m_DLLResultat=-2;

                VERIFY(m_pGetPosTVRO= (PGetPosTVRO) GetProcAddress(m_LStep4,"LSX_GetPosTVRO"));
                if (!m_pGetPosTVRO) m_DLLResultat=-2;

                VERIFY(m_pMoveAbsTVRO= (PMoveAbsTVRO) GetProcAddress(m_LStep4,"LSX_MoveAbsTVRO"));
                if (!m_pMoveAbsTVRO) m_DLLResultat=-2;

                VERIFY(m_pMoveRelTVRO= (PMoveRelTVRO) GetProcAddress(m_LStep4,"LSX_MoveRelTVRO"));
                if (!m_pMoveRelTVRO) m_DLLResultat=-2;

                VERIFY(m_pMoveRelTVROSingleAxis= (PMoveRelTVROSingleAxis) GetProcAddress(m_LStep4,"LSX_MoveRelTVROSingleAxis"));
                if (!m_pMoveRelTVROSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pMoveAbsTVROSingleAxis= (PMoveAbsTVROSingleAxis) GetProcAddress(m_LStep4,"LSX_MoveAbsTVROSingleAxis"));
                if (!m_pMoveAbsTVROSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pGetStatusTVRO= (PGetStatusTVRO) GetProcAddress(m_LStep4,"LSX_GetStatusTVRO"));
                if (!m_pGetStatusTVRO) m_DLLResultat=-2;

                VERIFY(m_pGetStatusTVROW= (PGetStatusTVROW) GetProcAddress(m_LStep4,"LSX_GetStatusTVROW"));
                if (!m_pGetStatusTVROW) m_DLLResultat=-2;

                VERIFY(m_pSetTargetWindow= (PSetTargetWindow) GetProcAddress(m_LStep4,"LSX_SetTargetWindow"));
                if (!m_pSetTargetWindow) m_DLLResultat=-2;

                VERIFY(m_pGetTargetWindow= (PGetTargetWindow) GetProcAddress(m_LStep4,"LSX_GetTargetWindow"));
                if (!m_pGetTargetWindow) m_DLLResultat=-2;

                VERIFY(m_pGetEncoderPeriod= (PGetEncoderPeriod) GetProcAddress(m_LStep4,"LSX_GetEncoderPeriod"));
                if (!m_pGetEncoderPeriod) m_DLLResultat=-2;

                VERIFY(m_pGetEncoderRefSignal= (PGetEncoderRefSignal) GetProcAddress(m_LStep4,"LSX_GetEncoderRefSignal"));
                if (!m_pGetEncoderRefSignal) m_DLLResultat=-2;

                VERIFY(m_pGetEncoderPosition= (PGetEncoderPosition) GetProcAddress(m_LStep4,"LSX_GetEncoderPosition"));
                if (!m_pGetEncoderPosition) m_DLLResultat=-2;

                VERIFY(m_pGetEncoderActive= (PGetEncoderActive) GetProcAddress(m_LStep4,"LSX_GetEncoderActive"));
                if (!m_pGetEncoderActive) m_DLLResultat=-2;

                VERIFY(m_pGetController= (PGetController) GetProcAddress(m_LStep4,"LSX_GetController"));
                if (!m_pGetController) m_DLLResultat=-2;

                VERIFY(m_pGetControllerCall= (PGetControllerCall) GetProcAddress(m_LStep4,"LSX_GetControllerCall"));
                if (!m_pGetControllerCall) m_DLLResultat=-2;

                VERIFY(m_pGetControllerSteps= (PGetControllerSteps) GetProcAddress(m_LStep4,"LSX_GetControllerSteps"));
                if (!m_pGetControllerSteps) m_DLLResultat=-2;

                VERIFY(m_pGetControllerFactor= (PGetControllerFactor) GetProcAddress(m_LStep4,"LSX_GetControllerFactor"));
                if (!m_pGetControllerFactor) m_DLLResultat=-2;

                VERIFY(m_pGetControllerTWDelay= (PGetControllerTWDelay) GetProcAddress(m_LStep4,"LSX_GetControllerTWDelay"));
                if (!m_pGetControllerTWDelay) m_DLLResultat=-2;

                VERIFY(m_pGetControllerTimeout= (PGetControllerTimeout) GetProcAddress(m_LStep4,"LSX_GetControllerTimeout"));
                if (!m_pGetControllerTimeout) m_DLLResultat=-2;

                VERIFY(m_pSetCtrFastMoveOn= (PSetCtrFastMoveOn) GetProcAddress(m_LStep4,"LSX_SetCtrFastMoveOn"));
                if (!m_pSetCtrFastMoveOn) m_DLLResultat=-2;

                VERIFY(m_pSetCtrFastMoveOff= (PSetCtrFastMoveOff) GetProcAddress(m_LStep4,"LSX_SetCtrFastMoveOff"));
                if (!m_pSetCtrFastMoveOff) m_DLLResultat=-2;

                VERIFY(m_pGetCtrFastMove= (PGetCtrFastMove) GetProcAddress(m_LStep4,"LSX_GetCtrFastMove"));
                if (!m_pGetCtrFastMove) m_DLLResultat=-2;

                VERIFY(m_pClearCtrFastMoveCounter= (PClearCtrFastMoveCounter) GetProcAddress(m_LStep4,"LSX_ClearCtrFastMoveCounter"));
                if (!m_pClearCtrFastMoveCounter) m_DLLResultat=-2;

                VERIFY(m_pGetCtrFastMoveCounter= (PGetCtrFastMoveCounter) GetProcAddress(m_LStep4,"LSX_GetCtrFastMoveCounter"));
                if (!m_pGetCtrFastMoveCounter) m_DLLResultat=-2;

                VERIFY(m_pClearEncoder= (PClearEncoder) GetProcAddress(m_LStep4,"LSX_ClearEncoder"));
                if (!m_pClearEncoder) m_DLLResultat=-2;

                VERIFY(m_pGetEncoder= (PGetEncoder) GetProcAddress(m_LStep4,"LSX_GetEncoder"));
                if (!m_pGetEncoder) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger= (PGetTrigger) GetProcAddress(m_LStep4,"LSX_GetTrigger"));
                if (!m_pGetTrigger) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_= (PGetTrigger_) GetProcAddress(m_LStep4,"LSX_GetTrigger_"));
                if (!m_pGetTrigger_) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerPar= (PGetTriggerPar) GetProcAddress(m_LStep4,"LSX_GetTriggerPar"));
                if (!m_pGetTriggerPar) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoPar= (PGetTrigger_TwoPar) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoPar"));
                if (!m_pGetTrigger_TwoPar) m_DLLResultat=-2;

                VERIFY(m_pSetTriggerCount= (PSetTriggerCount) GetProcAddress(m_LStep4,"LSX_SetTriggerCount"));
                if (!m_pSetTriggerCount) m_DLLResultat=-2;

                VERIFY(m_pGetTriggerCount= (PGetTriggerCount) GetProcAddress(m_LStep4,"LSX_GetTriggerCount"));
                if (!m_pGetTriggerCount) m_DLLResultat=-2;

                VERIFY(m_pSetTrigCount= (PSetTrigCount) GetProcAddress(m_LStep4,"LSX_SetTrigCount"));
                if (!m_pSetTrigCount) m_DLLResultat=-2;

                VERIFY(m_pGetTrigCount= (PGetTrigCount) GetProcAddress(m_LStep4,"LSX_GetTrigCount"));
                if (!m_pGetTrigCount) m_DLLResultat=-2;

                VERIFY(m_pSetTrigger_TwoCount= (PSetTrigger_TwoCount) GetProcAddress(m_LStep4,"LSX_SetTrigger_TwoCount"));
                if (!m_pSetTrigger_TwoCount) m_DLLResultat=-2;

                VERIFY(m_pGetTrigger_TwoCount= (PGetTrigger_TwoCount) GetProcAddress(m_LStep4,"LSX_GetTrigger_TwoCount"));
                if (!m_pGetTrigger_TwoCount) m_DLLResultat=-2;

                VERIFY(m_pSetSnapShotSource= (PSetSnapShotSource) GetProcAddress(m_LStep4,"LSX_SetSnapShotSource"));
                if (!m_pSetSnapShotSource) m_DLLResultat=-2;

                VERIFY(m_pGetSnapShotSource= (PGetSnapShotSource) GetProcAddress(m_LStep4,"LSX_GetSnapShotSource"));
                if (!m_pGetSnapShotSource) m_DLLResultat=-2;

                VERIFY(m_pSetTVRInPulse= (PSetTVRInPulse) GetProcAddress(m_LStep4,"LSX_SetTVRInPulse"));
                if (!m_pSetTVRInPulse) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshot= (PGetSnapshot) GetProcAddress(m_LStep4,"LSX_GetSnapshot"));
                if (!m_pGetSnapshot) m_DLLResultat=-2;

                VERIFY(m_pSetSnapshotFilter= (PSetSnapshotFilter) GetProcAddress(m_LStep4,"LSX_SetSnapshotFilter"));
                if (!m_pSetSnapshotFilter) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshotFilter= (PGetSnapshotFilter) GetProcAddress(m_LStep4,"LSX_GetSnapshotFilter"));
                if (!m_pGetSnapshotFilter) m_DLLResultat=-2;

                VERIFY(m_pGetSnapshotPar= (PGetSnapshotPar) GetProcAddress(m_LStep4,"LSX_GetSnapshotPar"));
                if (!m_pGetSnapshotPar) m_DLLResultat=-2;

                VERIFY(m_pGetLimit= (PGetLimit) GetProcAddress(m_LStep4,"LSX_GetLimit"));
                if (!m_pGetLimit) m_DLLResultat=-2;

                VERIFY(m_pJoyChangeAxis= (PJoyChangeAxis) GetProcAddress(m_LStep4,"LSX_JoyChangeAxis"));
                if (!m_pJoyChangeAxis) m_DLLResultat=-2;

                VERIFY(m_pGetJoyChangeAxis= (PGetJoyChangeAxis) GetProcAddress(m_LStep4,"LSX_GetJoyChangeAxis"));
                if (!m_pGetJoyChangeAxis) m_DLLResultat=-2;

                VERIFY(m_pSetDigJoyOff= (PSetDigJoyOff) GetProcAddress(m_LStep4,"LSX_SetDigJoyOff"));
                if (!m_pSetDigJoyOff) m_DLLResultat=-2;

                VERIFY(m_pSetInputTrigMove= (PSetInputTrigMove) GetProcAddress(m_LStep4,"LSX_SetInputTrigMove"));
                if (!m_pSetInputTrigMove) m_DLLResultat=-2;

                VERIFY(m_pGetInputTrigMove= (PGetInputTrigMove) GetProcAddress(m_LStep4,"LSX_GetInputTrigMove"));
                if (!m_pGetInputTrigMove) m_DLLResultat=-2;

                VERIFY(m_pSetLimitControlMode= (PSetLimitControlMode) GetProcAddress(m_LStep4,"LSX_SetLimitControlMode"));
                if (!m_pSetLimitControlMode) m_DLLResultat=-2;

                VERIFY(m_pGetLimitControlMode= (PGetLimitControlMode) GetProcAddress(m_LStep4,"LSX_GetLimitControlMode"));
                if (!m_pGetLimitControlMode) m_DLLResultat=-2;

                VERIFY(m_pInitialize= (PInitialize) GetProcAddress(m_LStep4,"LSX_Initialize"));
                if (!m_pInitialize) m_DLLResultat=-2;

                VERIFY(m_pInitializeW= (PInitializeW) GetProcAddress(m_LStep4,"LSX_InitializeW"));
                if (!m_pInitializeW) m_DLLResultat=-2;

                VERIFY(m_pSetAccelJerk= (PSetAccelJerk) GetProcAddress(m_LStep4,"LSX_SetAccelJerk"));
                if (!m_pSetAccelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetDecelJerk= (PSetDecelJerk) GetProcAddress(m_LStep4,"LSX_SetDecelJerk"));
                if (!m_pSetDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetCalibRMJerk= (PSetCalibRMJerk) GetProcAddress(m_LStep4,"LSX_SetCalibRMJerk"));
                if (!m_pSetCalibRMJerk) m_DLLResultat=-2;

                VERIFY(m_pSetJoyVel= (PSetJoyVel) GetProcAddress(m_LStep4,"LSX_SetJoyVel"));
                if (!m_pSetJoyVel) m_DLLResultat=-2;

                VERIFY(m_pGetJoyVel= (PGetJoyVel) GetProcAddress(m_LStep4,"LSX_GetJoyVel"));
                if (!m_pGetJoyVel) m_DLLResultat=-2;

                VERIFY(m_pSetJoyOutPass= (PSetJoyOutPass) GetProcAddress(m_LStep4,"LSX_SetJoyOutPass"));
                if (!m_pSetJoyOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetJoyOutPass= (PGetJoyOutPass) GetProcAddress(m_LStep4,"LSX_GetJoyOutPass"));
                if (!m_pGetJoyOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetTippOutPass= (PSetTippOutPass) GetProcAddress(m_LStep4,"LSX_SetTippOutPass"));
                if (!m_pSetTippOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetTippOutPass= (PGetTippOutPass) GetProcAddress(m_LStep4,"LSX_GetTippOutPass"));
                if (!m_pGetTippOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetMotorBrakeDigOut= (PSetMotorBrakeDigOut) GetProcAddress(m_LStep4,"LSX_SetMotorBrakeDigOut"));
                if (!m_pSetMotorBrakeDigOut) m_DLLResultat=-2;

                VERIFY(m_pGetMotorBrakeDigOut= (PGetMotorBrakeDigOut) GetProcAddress(m_LStep4,"LSX_GetMotorBrakeDigOut"));
                if (!m_pGetMotorBrakeDigOut) m_DLLResultat=-2;

                VERIFY(m_pGetMotorBrakeOut= (PGetMotorBrakeOut) GetProcAddress(m_LStep4,"LSX_GetMotorBrakeOut"));
                if (!m_pGetMotorBrakeOut) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBall= (PSetTrackBall) GetProcAddress(m_LStep4,"LSX_SetTrackBall"));
                if (!m_pSetTrackBall) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBall= (PGetTrackBall) GetProcAddress(m_LStep4,"LSX_GetTrackBall"));
                if (!m_pGetTrackBall) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallVel= (PSetTrackBallVel) GetProcAddress(m_LStep4,"LSX_SetTrackBallVel"));
                if (!m_pSetTrackBallVel) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallVel= (PGetTrackBallVel) GetProcAddress(m_LStep4,"LSX_GetTrackBallVel"));
                if (!m_pGetTrackBallVel) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallEnable= (PSetTrackBallEnable) GetProcAddress(m_LStep4,"LSX_SetTrackBallEnable"));
                if (!m_pSetTrackBallEnable) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallEnable= (PGetTrackBallEnable) GetProcAddress(m_LStep4,"LSX_GetTrackBallEnable"));
                if (!m_pGetTrackBallEnable) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallRedCur= (PSetTrackBallRedCur) GetProcAddress(m_LStep4,"LSX_SetTrackBallRedCur"));
                if (!m_pSetTrackBallRedCur) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallRedCur= (PGetTrackBallRedCur) GetProcAddress(m_LStep4,"LSX_GetTrackBallRedCur"));
                if (!m_pGetTrackBallRedCur) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallDir= (PSetTrackBallDir) GetProcAddress(m_LStep4,"LSX_SetTrackBallDir"));
                if (!m_pSetTrackBallDir) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallDir= (PGetTrackBallDir) GetProcAddress(m_LStep4,"LSX_GetTrackBallDir"));
                if (!m_pGetTrackBallDir) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallToAxis= (PSetTrackBallToAxis) GetProcAddress(m_LStep4,"LSX_SetTrackBallToAxis"));
                if (!m_pSetTrackBallToAxis) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallToAxis= (PGetTrackBallToAxis) GetProcAddress(m_LStep4,"LSX_GetTrackBallToAxis"));
                if (!m_pGetTrackBallToAxis) m_DLLResultat=-2;

                VERIFY(m_pSetTrackBallOutPass= (PSetTrackBallOutPass) GetProcAddress(m_LStep4,"LSX_SetTrackBallOutPass"));
                if (!m_pSetTrackBallOutPass) m_DLLResultat=-2;

                VERIFY(m_pGetTrackBallOutPass= (PGetTrackBallOutPass) GetProcAddress(m_LStep4,"LSX_GetTrackBallOutPass"));
                if (!m_pGetTrackBallOutPass) m_DLLResultat=-2;

                VERIFY(m_pSetDigInStatus= (PSetDigInStatus) GetProcAddress(m_LStep4,"LSX_SetDigInStatus"));
                if (!m_pSetDigInStatus) m_DLLResultat=-2;

                VERIFY(m_pSetDigInStatusW= (PSetDigInStatusW) GetProcAddress(m_LStep4,"LSX_SetDigInStatusW"));
                if (!m_pSetDigInStatusW) m_DLLResultat=-2;

                VERIFY(m_pGetDigInStatus= (PGetDigInStatus) GetProcAddress(m_LStep4,"LSX_GetDigInStatus"));
                if (!m_pGetDigInStatus) m_DLLResultat=-2;

                VERIFY(m_pSetDigInExtStatus= (PSetDigInExtStatus) GetProcAddress(m_LStep4,"LSX_SetDigInExtStatus"));
                if (!m_pSetDigInExtStatus) m_DLLResultat=-2;

                VERIFY(m_pSetDigInExtStatusW= (PSetDigInExtStatusW) GetProcAddress(m_LStep4,"LSX_SetDigInExtStatusW"));
                if (!m_pSetDigInExtStatusW) m_DLLResultat=-2;

                VERIFY(m_pGetDigInExtStatus= (PGetDigInExtStatus) GetProcAddress(m_LStep4,"LSX_GetDigInExtStatus"));
                if (!m_pGetDigInExtStatus) m_DLLResultat=-2;

                VERIFY(m_pSetTTLDigOut= (PSetTTLDigOut) GetProcAddress(m_LStep4,"LSX_SetTTLDigOut"));
                if (!m_pSetTTLDigOut) m_DLLResultat=-2;

                VERIFY(m_pGetTTLDigOut= (PGetTTLDigOut) GetProcAddress(m_LStep4,"LSX_GetTTLDigOut"));
                if (!m_pGetTTLDigOut) m_DLLResultat=-2;

                VERIFY(m_pGetTTLDigIn= (PGetTTLDigIn) GetProcAddress(m_LStep4,"LSX_GetTTLDigIn"));
                if (!m_pGetTTLDigIn) m_DLLResultat=-2;

                VERIFY(m_pSetTVR= (PSetTVR) GetProcAddress(m_LStep4,"LSX_SetTVR"));
                if (!m_pSetTVR) m_DLLResultat=-2;

                VERIFY(m_pGetTVR= (PGetTVR) GetProcAddress(m_LStep4,"LSX_GetTVR"));
                if (!m_pGetTVR) m_DLLResultat=-2;

                VERIFY(m_pSetTVRToAxis= (PSetTVRToAxis) GetProcAddress(m_LStep4,"LSX_SetTVRToAxis"));
                if (!m_pSetTVRToAxis) m_DLLResultat=-2;

                VERIFY(m_pGetTVRToAxis= (PGetTVRToAxis) GetProcAddress(m_LStep4,"LSX_GetTVRToAxis"));
                if (!m_pGetTVRToAxis) m_DLLResultat=-2;

                VERIFY(m_pSetDeceleration= (PSetDeceleration) GetProcAddress(m_LStep4,"LSX_SetDeceleration"));
                if (!m_pSetDeceleration) m_DLLResultat=-2;

                VERIFY(m_pGetDeceleration= (PGetDeceleration) GetProcAddress(m_LStep4,"LSX_GetDeceleration"));
                if (!m_pGetDeceleration) m_DLLResultat=-2;

                VERIFY(m_pSetDecelSingleAxis= (PSetDecelSingleAxis) GetProcAddress(m_LStep4,"LSX_SetDecelSingleAxis"));
                if (!m_pSetDecelSingleAxis) m_DLLResultat=-2;

                VERIFY(m_pConfigMaxAxes= (PConfigMaxAxes) GetProcAddress(m_LStep4,"LSX_ConfigMaxAxes"));
                if (!m_pConfigMaxAxes) m_DLLResultat=-2;

                VERIFY(m_pSetMotorBrake= (PSetMotorBrake) GetProcAddress(m_LStep4,"LSX_SetMotorBrake"));
                if (!m_pSetMotorBrake) m_DLLResultat=-2;

                VERIFY(m_pGetMotorBrake= (PGetMotorBrake) GetProcAddress(m_LStep4,"LSX_GetMotorBrake"));
                if (!m_pGetMotorBrake) m_DLLResultat=-2;

                VERIFY(m_pSetJoystickAxes= (PSetJoystickAxes) GetProcAddress(m_LStep4,"LSX_SetJoystickAxes"));
                if (!m_pSetJoystickAxes) m_DLLResultat=-2;

                VERIFY(m_pGetJoystickAxes= (PGetJoystickAxes) GetProcAddress(m_LStep4,"LSX_GetJoystickAxes"));
                if (!m_pGetJoystickAxes) m_DLLResultat=-2;

                VERIFY(m_pSetJoyVelSkal= (PSetJoyVelSkal) GetProcAddress(m_LStep4,"LSX_SetJoyVelSkal"));
                if (!m_pSetJoyVelSkal) m_DLLResultat=-2;

                VERIFY(m_pGetJoyVelSkal= (PGetJoyVelSkal) GetProcAddress(m_LStep4,"LSX_GetJoyVelSkal"));
                if (!m_pGetJoyVelSkal) m_DLLResultat=-2;

                VERIFY(m_pSetMaxUserCurrent= (PSetMaxUserCurrent) GetProcAddress(m_LStep4,"LSX_SetMaxUserCurrent"));
                if (!m_pSetMaxUserCurrent) m_DLLResultat=-2;

                VERIFY(m_pGetMaxUserCurrent= (PGetMaxUserCurrent) GetProcAddress(m_LStep4,"LSX_GetMaxUserCurrent"));
                if (!m_pGetMaxUserCurrent) m_DLLResultat=-2;

                VERIFY(m_pSetStopDecel= (PSetStopDecel) GetProcAddress(m_LStep4,"LSX_SetStopDecel"));
                if (!m_pSetStopDecel) m_DLLResultat=-2;

                VERIFY(m_pGetStopDecel= (PGetStopDecel) GetProcAddress(m_LStep4,"LSX_GetStopDecel"));
                if (!m_pGetStopDecel) m_DLLResultat=-2;

                VERIFY(m_pSetMotorMaxVel= (PSetMotorMaxVel) GetProcAddress(m_LStep4,"LSX_SetMotorMaxVel"));
                if (!m_pSetMotorMaxVel) m_DLLResultat=-2;

                VERIFY(m_pGetMotorMaxVel= (PGetMotorMaxVel) GetProcAddress(m_LStep4,"LSX_GetMotorMaxVel"));
                if (!m_pGetMotorMaxVel) m_DLLResultat=-2;

                VERIFY(m_pSetMotorStandForce= (PSetMotorStandForce) GetProcAddress(m_LStep4,"LSX_SetMotorStandForce"));
                if (!m_pSetMotorStandForce) m_DLLResultat=-2;

                VERIFY(m_pGetMotorStandForce= (PGetMotorStandForce) GetProcAddress(m_LStep4,"LSX_GetMotorStandForce"));
                if (!m_pGetMotorStandForce) m_DLLResultat=-2;

                VERIFY(m_pSetMotorStandMoment= (PSetMotorStandMoment) GetProcAddress(m_LStep4,"LSX_SetMotorStandMoment"));
                if (!m_pSetMotorStandMoment) m_DLLResultat=-2;

                VERIFY(m_pGetMotorStandMoment= (PGetMotorStandMoment) GetProcAddress(m_LStep4,"LSX_GetMotorStandMoment"));
                if (!m_pGetMotorStandMoment) m_DLLResultat=-2;

                VERIFY(m_pSetMotorFieldDir= (PSetMotorFieldDir) GetProcAddress(m_LStep4,"LSX_SetMotorFieldDir"));
                if (!m_pSetMotorFieldDir) m_DLLResultat=-2;

                VERIFY(m_pGetMotorFieldDir= (PGetMotorFieldDir) GetProcAddress(m_LStep4,"LSX_GetMotorFieldDir"));
                if (!m_pGetMotorFieldDir) m_DLLResultat=-2;

                VERIFY(m_pSetMotorType= (PSetMotorType) GetProcAddress(m_LStep4,"LSX_SetMotorType"));
                if (!m_pSetMotorType) m_DLLResultat=-2;

                VERIFY(m_pGetMotorType= (PGetMotorType) GetProcAddress(m_LStep4,"LSX_GetMotorType"));
                if (!m_pGetMotorType) m_DLLResultat=-2;

                VERIFY(m_pSetOsziCallBackFct= (PSetOsziCallBackFct) GetProcAddress(m_LStep4,"LSX_SetOsziCallBackFct"));
                if (!m_pSetOsziCallBackFct) m_DLLResultat=-2;

                VERIFY(m_pTranslateErrMsg= (PTranslateErrMsg) GetProcAddress(m_LStep4,"LSX_TranslateErrMsg"));
                if (!m_pTranslateErrMsg) m_DLLResultat=-2;

                VERIFY(m_pSetCalibRMAccel= (PSetCalibRMAccel) GetProcAddress(m_LStep4,"LSX_SetCalibRMAccel"));
                if (!m_pSetCalibRMAccel) m_DLLResultat=-2;

                VERIFY(m_pGetCalibRMAccel= (PGetCalibRMAccel) GetProcAddress(m_LStep4,"LSX_GetCalibRMAccel"));
                if (!m_pGetCalibRMAccel) m_DLLResultat=-2;

                VERIFY(m_pGetCalibRMJerk= (PGetCalibRMJerk) GetProcAddress(m_LStep4,"LSX_GetCalibRMJerk"));
                if (!m_pGetCalibRMJerk) m_DLLResultat=-2;

                VERIFY(m_pSetCalibRMVel= (PSetCalibRMVel) GetProcAddress(m_LStep4,"LSX_SetCalibRMVel"));
                if (!m_pSetCalibRMVel) m_DLLResultat=-2;

                VERIFY(m_pGetCalibRMVel= (PGetCalibRMVel) GetProcAddress(m_LStep4,"LSX_GetCalibRMVel"));
                if (!m_pGetCalibRMVel) m_DLLResultat=-2;

                VERIFY(m_pSetCalibRMBackSpeed= (PSetCalibRMBackSpeed) GetProcAddress(m_LStep4,"LSX_SetCalibRMBackSpeed"));
                if (!m_pSetCalibRMBackSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetCalibRMBackSpeed= (PGetCalibRMBackSpeed) GetProcAddress(m_LStep4,"LSX_GetCalibRMBackSpeed"));
                if (!m_pGetCalibRMBackSpeed) m_DLLResultat=-2;

                VERIFY(m_pGetAccelJerk= (PGetAccelJerk) GetProcAddress(m_LStep4,"LSX_GetAccelJerk"));
                if (!m_pGetAccelJerk) m_DLLResultat=-2;

                VERIFY(m_pGetDecelJerk= (PGetDecelJerk) GetProcAddress(m_LStep4,"LSX_GetDecelJerk"));
                if (!m_pGetDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetGearDenominator= (PSetGearDenominator) GetProcAddress(m_LStep4,"LSX_SetGearDenominator"));
                if (!m_pSetGearDenominator) m_DLLResultat=-2;

                VERIFY(m_pGetGearDenominator= (PGetGearDenominator) GetProcAddress(m_LStep4,"LSX_GetGearDenominator"));
                if (!m_pGetGearDenominator) m_DLLResultat=-2;

                VERIFY(m_pSetGearNumerator= (PSetGearNumerator) GetProcAddress(m_LStep4,"LSX_SetGearNumerator"));
                if (!m_pSetGearNumerator) m_DLLResultat=-2;

                VERIFY(m_pGetGearNumerator= (PGetGearNumerator) GetProcAddress(m_LStep4,"LSX_GetGearNumerator"));
                if (!m_pGetGearNumerator) m_DLLResultat=-2;

                VERIFY(m_pSetStopDecelJerk= (PSetStopDecelJerk) GetProcAddress(m_LStep4,"LSX_SetStopDecelJerk"));
                if (!m_pSetStopDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pGetStopDecelJerk= (PGetStopDecelJerk) GetProcAddress(m_LStep4,"LSX_GetStopDecelJerk"));
                if (!m_pGetStopDecelJerk) m_DLLResultat=-2;

                VERIFY(m_pSetSwChange= (PSetSwChange) GetProcAddress(m_LStep4,"LSX_SetSwChange"));
                if (!m_pSetSwChange) m_DLLResultat=-2;

                VERIFY(m_pGetSwChange= (PGetSwChange) GetProcAddress(m_LStep4,"LSX_GetSwChange"));
                if (!m_pGetSwChange) m_DLLResultat=-2;

                VERIFY(m_pSetExtCallBackFct= (PSetExtCallBackFct) GetProcAddress(m_LStep4,"LSX_SetExtCallBackFct"));
                if (!m_pSetExtCallBackFct) m_DLLResultat=-2;

                VERIFY(m_pCreateLSID= (PCreateLSID) GetProcAddress(m_LStep4,"LSX_CreateLSID"));
                if (!m_pCreateLSID) m_DLLResultat=-2;

                VERIFY(m_pFreeLSID= (PFreeLSID) GetProcAddress(m_LStep4,"LSX_FreeLSID"));
                if (!m_pFreeLSID) m_DLLResultat=-2;

                if (!m_DLLResultat) m_pCreateLSID(&m_LSID);
        }
}


// Destruktor
CLStep64::~CLStep64()
{
	if (m_LStep4!=0)
	{
             m_pFreeLSID(m_LSID);
             FreeLibrary(m_LStep4); // DLL wieder freigeben
	}
}


// gekapselte Funktionen der DLL

int CLStep64::Connect ()
{
        if (m_pConnect)
        {
                return m_pConnect (m_LSID);
        }
        else
                return -1;
}

int CLStep64::ConnectSimple (int lAnInterfaceType, char *pcAComName, int lABaudRate, BOOL bAShowProt)
{
        if (m_pConnectSimple)
        {
                return m_pConnectSimple (m_LSID, lAnInterfaceType, pcAComName, lABaudRate, bAShowProt);
        }
        else
                return -1;
}

int CLStep64::ConnectSimpleW (int lAnInterfaceType, TCHAR *pcAComName, int lABaudRate, BOOL bAShowProt)
{
        if (m_pConnectSimpleW)
        {
                return m_pConnectSimpleW (m_LSID, lAnInterfaceType, pcAComName, lABaudRate, bAShowProt);
        }
        else
                return -1;
}

int CLStep64::ConnectEx (TLS_ControlInitPar *pAControlInitPar)
{
        if (m_pConnectEx)
        {
                return m_pConnectEx (m_LSID, pAControlInitPar);
        }
        else
                return -1;
}

int CLStep64::ConnectExW (TLS_ControlInitParW *pAControlInitPar)
{
        if (m_pConnectExW)
        {
                return m_pConnectExW (m_LSID, pAControlInitPar);
        }
        else
                return -1;
}

int CLStep64::Disconnect ()
{
        if (m_pDisconnect)
        {
                return m_pDisconnect (m_LSID);
        }
        else
                return -1;
}

int CLStep64::LoadConfig (char *pcFileName)
{
        if (m_pLoadConfig)
        {
                return m_pLoadConfig (m_LSID, pcFileName);
        }
        else
                return -1;
}

int CLStep64::LoadConfigW (TCHAR *pcFileName)
{
        if (m_pLoadConfigW)
        {
                return m_pLoadConfigW (m_LSID, pcFileName);
        }
        else
                return -1;
}

int CLStep64::SaveConfig (char *pcFileName)
{
        if (m_pSaveConfig)
        {
                return m_pSaveConfig (m_LSID, pcFileName);
        }
        else
                return -1;
}

int CLStep64::SaveConfigW (TCHAR *pcFileName)
{
        if (m_pSaveConfigW)
        {
                return m_pSaveConfigW (m_LSID, pcFileName);
        }
        else
                return -1;
}

int CLStep64::MoveAbs (double dX, double dY, double dZ, double dA, BOOL bWait)
{
        if (m_pMoveAbs)
        {
                return m_pMoveAbs (m_LSID, dX, dY, dZ, dA, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveRel (double dX, double dY, double dZ, double dA, BOOL bWait)
{
        if (m_pMoveRel)
        {
                return m_pMoveRel (m_LSID, dX, dY, dZ, dA, bWait);
        }
        else
                return -1;
}

int CLStep64::Calibrate ()
{
        if (m_pCalibrate)
        {
                return m_pCalibrate (m_LSID);
        }
        else
                return -1;
}

int CLStep64::RMeasure ()
{
        if (m_pRMeasure)
        {
                return m_pRMeasure (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetPitch (double dX, double dY, double dZ, double dA)
{
        if (m_pSetPitch)
        {
                return m_pSetPitch (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetPos (double dX, double dY, double dZ, double dA)
{
        if (m_pSetPos)
        {
                return m_pSetPos (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetActiveAxes (int lFlags)
{
        if (m_pSetActiveAxes)
        {
                return m_pSetActiveAxes (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::SetVel (double dX, double dY, double dZ, double dA)
{
        if (m_pSetVel)
        {
                return m_pSetVel (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetAccel (double dX, double dY, double dZ, double dA)
{
        if (m_pSetAccel)
        {
                return m_pSetAccel (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetRoomAccelJerk (double dvalue)
{
        if (m_pSetRoomAccelJerk)
        {
                return m_pSetRoomAccelJerk (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomAccelJerk (double *pdvalue)
{
        if (m_pGetRoomAccelJerk)
        {
                return m_pGetRoomAccelJerk (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomDecelJerk (double dvalue)
{
        if (m_pSetRoomDecelJerk)
        {
                return m_pSetRoomDecelJerk (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomDecelJerk (double *pdvalue)
{
        if (m_pGetRoomDecelJerk)
        {
                return m_pGetRoomDecelJerk (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomStopJerk (double dvalue)
{
        if (m_pSetRoomStopJerk)
        {
                return m_pSetRoomStopJerk (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomStopJerk (double *pdvalue)
{
        if (m_pGetRoomStopJerk)
        {
                return m_pGetRoomStopJerk (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomAccel (double dvalue)
{
        if (m_pSetRoomAccel)
        {
                return m_pSetRoomAccel (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomAccel (double *pdvalue)
{
        if (m_pGetRoomAccel)
        {
                return m_pGetRoomAccel (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomDecel (double dvalue)
{
        if (m_pSetRoomDecel)
        {
                return m_pSetRoomDecel (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomDecel (double *pdvalue)
{
        if (m_pGetRoomDecel)
        {
                return m_pGetRoomDecel (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomStopDecel (double dvalue)
{
        if (m_pSetRoomStopDecel)
        {
                return m_pSetRoomStopDecel (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomStopDecel (double *pdvalue)
{
        if (m_pGetRoomStopDecel)
        {
                return m_pGetRoomStopDecel (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetRoomVel (double dvalue)
{
        if (m_pSetRoomVel)
        {
                return m_pSetRoomVel (m_LSID, dvalue);
        }
        else
                return -1;
}

int CLStep64::GetRoomVel (double *pdvalue)
{
        if (m_pGetRoomVel)
        {
                return m_pGetRoomVel (m_LSID, pdvalue);
        }
        else
                return -1;
}

int CLStep64::SetReduction (double dX, double dY, double dZ, double dA)
{
        if (m_pSetReduction)
        {
                return m_pSetReduction (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetDelay (int lDelay)
{
        if (m_pSetDelay)
        {
                return m_pSetDelay (m_LSID, lDelay);
        }
        else
                return -1;
}

int CLStep64::SetSwitchPolarity (int lXP, int lYP, int lZP, int lAP)
{
        if (m_pSetSwitchPolarity)
        {
                return m_pSetSwitchPolarity (m_LSID, lXP, lYP, lZP, lAP);
        }
        else
                return -1;
}

int CLStep64::SetSwitchActive (int lXA, int lYA, int lZA, int lAA)
{
        if (m_pSetSwitchActive)
        {
                return m_pSetSwitchActive (m_LSID, lXA, lYA, lZA, lAA);
        }
        else
                return -1;
}

int CLStep64::SetJoystickOn (BOOL bPositionCount, BOOL bEncoder)
{
        if (m_pSetJoystickOn)
        {
                return m_pSetJoystickOn (m_LSID, bPositionCount, bEncoder);
        }
        else
                return -1;
}

int CLStep64::SetJoystickOff ()
{
        if (m_pSetJoystickOff)
        {
                return m_pSetJoystickOff (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SoftwareReset ()
{
        if (m_pSoftwareReset)
        {
                return m_pSoftwareReset (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetDigitalOutput (int lIndex, BOOL bValue)
{
        if (m_pSetDigitalOutput)
        {
                return m_pSetDigitalOutput (m_LSID, lIndex, bValue);
        }
        else
                return -1;
}

int CLStep64::GetDigitalInputs (int *plValue)
{
        if (m_pGetDigitalInputs)
        {
                return m_pGetDigitalInputs (m_LSID, plValue);
        }
        else
                return -1;
}

int CLStep64::SetAnalogOutput (int lIndex, int lValue)
{
        if (m_pSetAnalogOutput)
        {
                return m_pSetAnalogOutput (m_LSID, lIndex, lValue);
        }
        else
                return -1;
}

int CLStep64::GetAnalogInput (int lIndex, int *plValue)
{
        if (m_pGetAnalogInput)
        {
                return m_pGetAnalogInput (m_LSID, lIndex, plValue);
        }
        else
                return -1;
}

int CLStep64::SetLimit (int lAxis, double dMinRange, double dMaxRange)
{
        if (m_pSetLimit)
        {
                return m_pSetLimit (m_LSID, lAxis, dMinRange, dMaxRange);
        }
        else
                return -1;
}

int CLStep64::SetLimitControl (int lAxis, BOOL bActive)
{
        if (m_pSetLimitControl)
        {
                return m_pSetLimitControl (m_LSID, lAxis, bActive);
        }
        else
                return -1;
}

int CLStep64::GetPos (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetPos)
        {
                return m_pGetPos (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetStatus (char *pcStat, int lMaxLen)
{
        if (m_pGetStatus)
        {
                return m_pGetStatus (m_LSID, pcStat, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStatusW (TCHAR *pcStat, int lMaxLen)
{
        if (m_pGetStatusW)
        {
                return m_pGetStatusW (m_LSID, pcStat, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetEncoderMask (int *plFlags)
{
        if (m_pGetEncoderMask)
        {
                return m_pGetEncoderMask (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::StopAxes ()
{
        if (m_pStopAxes)
        {
                return m_pStopAxes (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetAbortFlag ()
{
        if (m_pSetAbortFlag)
        {
                return m_pSetAbortFlag (m_LSID);
        }
        else
                return -1;
}

int CLStep64::MoveRelSingleAxis (int lAxis, double dValue, BOOL bWait)
{
        if (m_pMoveRelSingleAxis)
        {
                return m_pMoveRelSingleAxis (m_LSID, lAxis, dValue, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveAbsSingleAxis (int lAxis, double dValue, BOOL bWait)
{
        if (m_pMoveAbsSingleAxis)
        {
                return m_pMoveAbsSingleAxis (m_LSID, lAxis, dValue, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveSequence (int lnMode, BOOL bWait)
{
        if (m_pMoveSequence)
        {
                return m_pMoveSequence (m_LSID, lnMode, bWait);
        }
        else
                return -1;
}

int CLStep64::SetControlPars ()
{
        if (m_pSetControlPars)
        {
                return m_pSetControlPars (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetMotorCurrent (double dX, double dY, double dZ, double dA)
{
        if (m_pSetMotorCurrent)
        {
                return m_pSetMotorCurrent (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetMotorAutoKommCurrent (double dX, double dY, double dZ, double dA)
{
        if (m_pSetMotorAutoKommCurrent)
        {
                return m_pSetMotorAutoKommCurrent (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetMotorAutoKommCurrent (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetMotorAutoKommCurrent)
        {
                return m_pGetMotorAutoKommCurrent (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetMotorpeakCurrent (double dX, double dY, double dZ, double dA)
{
        if (m_pSetMotorpeakCurrent)
        {
                return m_pSetMotorpeakCurrent (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetMotorpeakCurrent (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetMotorpeakCurrent)
        {
                return m_pGetMotorpeakCurrent (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetMotorpeakCurrentTime (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMotorpeakCurrentTime)
        {
                return m_pSetMotorpeakCurrentTime (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMotorpeakCurrentTime (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMotorpeakCurrentTime)
        {
                return m_pGetMotorpeakCurrentTime (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetMotorIITCheck (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetMotorIITCheck)
        {
                return m_pSetMotorIITCheck (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetMotorIITCheck (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetMotorIITCheck)
        {
                return m_pGetMotorIITCheck (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetVelSingleAxis (int lAxis, double dVel)
{
        if (m_pSetVelSingleAxis)
        {
                return m_pSetVelSingleAxis (m_LSID, lAxis, dVel);
        }
        else
                return -1;
}

int CLStep64::SetAccelSingleAxis (int lAxis, double dAccel)
{
        if (m_pSetAccelSingleAxis)
        {
                return m_pSetAccelSingleAxis (m_LSID, lAxis, dAccel);
        }
        else
                return -1;
}

int CLStep64::CalibrateEx (int lFlags)
{
        if (m_pCalibrateEx)
        {
                return m_pCalibrateEx (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::RMeasureEx (int lFlags)
{
        if (m_pRMeasureEx)
        {
                return m_pRMeasureEx (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::SetShowProt (BOOL bShowProt)
{
        if (m_pSetShowProt)
        {
                return m_pSetShowProt (m_LSID, bShowProt);
        }
        else
                return -1;
}

int CLStep64::GetAnalogInputs2 (int *plPT100, int *plMV, int *plV24)
{
        if (m_pGetAnalogInputs2)
        {
                return m_pGetAnalogInputs2 (m_LSID, plPT100, plMV, plV24);
        }
        else
                return -1;
}

int CLStep64::SendString (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut)
{
        if (m_pSendString)
        {
                return m_pSendString (m_LSID, pcStr, pcRet, lMaxLen, bReadLine, lTimeOut);
        }
        else
                return -1;
}

int CLStep64::SendStringW (TCHAR *pcStr, TCHAR *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut)
{
        if (m_pSendStringW)
        {
                return m_pSendStringW (m_LSID, pcStr, pcRet, lMaxLen, bReadLine, lTimeOut);
        }
        else
                return -1;
}

int CLStep64::SetSpeedPoti (BOOL bSpeedPoti)
{
        if (m_pSetSpeedPoti)
        {
                return m_pSetSpeedPoti (m_LSID, bSpeedPoti);
        }
        else
                return -1;
}

int CLStep64::SetTVRMode (int lXT, int lYT, int lZT, int lAT)
{
        if (m_pSetTVRMode)
        {
                return m_pSetTVRMode (m_LSID, lXT, lYT, lZT, lAT);
        }
        else
                return -1;
}

int CLStep64::SetAutoStatus (int lValue)
{
        if (m_pSetAutoStatus)
        {
                return m_pSetAutoStatus (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::GetStatusAxis (char *pcStatusAxisStr, int lMaxLen)
{
        if (m_pGetStatusAxis)
        {
                return m_pGetStatusAxis (m_LSID, pcStatusAxisStr, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStatusAxisW (TCHAR *pcStatusAxisStr, int lMaxLen)
{
        if (m_pGetStatusAxisW)
        {
                return m_pGetStatusAxisW (m_LSID, pcStatusAxisStr, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetDigIO_Off (int lIndex)
{
        if (m_pSetDigIO_Off)
        {
                return m_pSetDigIO_Off (m_LSID, lIndex);
        }
        else
                return -1;
}

int CLStep64::SetDigIO_Polarity (int lIndex, BOOL bHigh)
{
        if (m_pSetDigIO_Polarity)
        {
                return m_pSetDigIO_Polarity (m_LSID, lIndex, bHigh);
        }
        else
                return -1;
}

int CLStep64::SetDigIO_EmergencyStop (int lIndex)
{
        if (m_pSetDigIO_EmergencyStop)
        {
                return m_pSetDigIO_EmergencyStop (m_LSID, lIndex);
        }
        else
                return -1;
}

int CLStep64::SetDigIO_Distance (int lIndex, BOOL bFkt, double dDist, int lAxis)
{
        if (m_pSetDigIO_Distance)
        {
                return m_pSetDigIO_Distance (m_LSID, lIndex, bFkt, dDist, lAxis);
        }
        else
                return -1;
}

int CLStep64::SetDimensions (int lXD, int lYD, int lZD, int lAD)
{
        if (m_pSetDimensions)
        {
                return m_pSetDimensions (m_LSID, lXD, lYD, lZD, lAD);
        }
        else
                return -1;
}

int CLStep64::MoveRelShort ()
{
        if (m_pMoveRelShort)
        {
                return m_pMoveRelShort (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetEncoderPeriod (double dX, double dY, double dZ, double dA)
{
        if (m_pSetEncoderPeriod)
        {
                return m_pSetEncoderPeriod (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetJoystickDir (int lXD, int lYD, int lZD, int lAD)
{
        if (m_pSetJoystickDir)
        {
                return m_pSetJoystickDir (m_LSID, lXD, lYD, lZD, lAD);
        }
        else
                return -1;
}

int CLStep64::SetEncoderMask (int lValue)
{
        if (m_pSetEncoderMask)
        {
                return m_pSetEncoderMask (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::SetGear (double dX, double dY, double dZ, double dA)
{
        if (m_pSetGear)
        {
                return m_pSetGear (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetHandWheelOn (BOOL bPositionCount, BOOL bEncoder)
{
        if (m_pSetHandWheelOn)
        {
                return m_pSetHandWheelOn (m_LSID, bPositionCount, bEncoder);
        }
        else
                return -1;
}

int CLStep64::SetHandWheelOff ()
{
        if (m_pSetHandWheelOff)
        {
                return m_pSetHandWheelOff (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetFactorTVR (double dX, double dY, double dZ, double dA)
{
        if (m_pSetFactorTVR)
        {
                return m_pSetFactorTVR (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetController (int lXC, int lYC, int lZC, int lAC)
{
        if (m_pSetController)
        {
                return m_pSetController (m_LSID, lXC, lYC, lZC, lAC);
        }
        else
                return -1;
}

int CLStep64::SetControllerCall (int lCtrCall)
{
        if (m_pSetControllerCall)
        {
                return m_pSetControllerCall (m_LSID, lCtrCall);
        }
        else
                return -1;
}

int CLStep64::SetControllerSteps (double dX, double dY, double dZ, double dA)
{
        if (m_pSetControllerSteps)
        {
                return m_pSetControllerSteps (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetControllerFactor (double dX, double dY, double dZ, double dA)
{
        if (m_pSetControllerFactor)
        {
                return m_pSetControllerFactor (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetControllerTWDelay (int lCtrTWDelay)
{
        if (m_pSetControllerTWDelay)
        {
                return m_pSetControllerTWDelay (m_LSID, lCtrTWDelay);
        }
        else
                return -1;
}

int CLStep64::SetEncoderRefSignal (int lXR, int lYR, int lZR, int lAR)
{
        if (m_pSetEncoderRefSignal)
        {
                return m_pSetEncoderRefSignal (m_LSID, lXR, lYR, lZR, lAR);
        }
        else
                return -1;
}

int CLStep64::SetEncoderPosition (BOOL bValue)
{
        if (m_pSetEncoderPosition)
        {
                return m_pSetEncoderPosition (m_LSID, bValue);
        }
        else
                return -1;
}

int CLStep64::GetVersionStr (char *pcVers, int lMaxLen)
{
        if (m_pGetVersionStr)
        {
                return m_pGetVersionStr (m_LSID, pcVers, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetVersionStrW (TCHAR *pcVers, int lMaxLen)
{
        if (m_pGetVersionStrW)
        {
                return m_pGetVersionStrW (m_LSID, pcVers, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetError (int *plErrorCode)
{
        if (m_pGetError)
        {
                return m_pGetError (m_LSID, plErrorCode);
        }
        else
                return -1;
}

int CLStep64::GetPosSingleAxis (int lAxis, double *pdPos)
{
        if (m_pGetPosSingleAxis)
        {
                return m_pGetPosSingleAxis (m_LSID, lAxis, pdPos);
        }
        else
                return -1;
}

int CLStep64::SetDistance (double dX, double dY, double dZ, double dA)
{
        if (m_pSetDistance)
        {
                return m_pSetDistance (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetPosEx (double *pdX, double *pdY, double *pdZ, double *pdA, BOOL bEncoder)
{
        if (m_pGetPosEx)
        {
                return m_pGetPosEx (m_LSID, pdX, pdY, pdZ, pdA, bEncoder);
        }
        else
                return -1;
}

int CLStep64::SetShowCmdList (BOOL bShowCmdList)
{
        if (m_pSetShowCmdList)
        {
                return m_pSetShowCmdList (m_LSID, bShowCmdList);
        }
        else
                return -1;
}

int CLStep64::SetWriteLogText (BOOL bAWriteLogText)
{
        if (m_pSetWriteLogText)
        {
                return m_pSetWriteLogText (m_LSID, bAWriteLogText);
        }
        else
                return -1;
}

int CLStep64::SetControllerTimeout (int lACtrTimeout)
{
        if (m_pSetControllerTimeout)
        {
                return m_pSetControllerTimeout (m_LSID, lACtrTimeout);
        }
        else
                return -1;
}

int CLStep64::SetEncoderActive (int lFlags)
{
        if (m_pSetEncoderActive)
        {
                return m_pSetEncoderActive (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::GetSnapshotCount (int *plSnsCount)
{
        if (m_pGetSnapshotCount)
        {
                return m_pGetSnapshotCount (m_LSID, plSnsCount);
        }
        else
                return -1;
}

int CLStep64::GetSnapshotPos (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetSnapshotPos)
        {
                return m_pGetSnapshotPos (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetCorrTblOff ()
{
        if (m_pSetCorrTblOff)
        {
                return m_pSetCorrTblOff (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetCorrTblOn (char *pcAFileName)
{
        if (m_pSetCorrTblOn)
        {
                return m_pSetCorrTblOn (m_LSID, pcAFileName);
        }
        else
                return -1;
}

int CLStep64::SetCorrTblOnW (TCHAR *pcAFileName)
{
        if (m_pSetCorrTblOnW)
        {
                return m_pSetCorrTblOnW (m_LSID, pcAFileName);
        }
        else
                return -1;
}

int CLStep64::SetFactorMode (BOOL bAFactorMode, double dX, double dY, double dZ, double dA)
{
        if (m_pSetFactorMode)
        {
                return m_pSetFactorMode (m_LSID, bAFactorMode, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetSnapshot (BOOL bASnapshot)
{
        if (m_pSetSnapshot)
        {
                return m_pSetSnapshot (m_LSID, bASnapshot);
        }
        else
                return -1;
}

int CLStep64::SetSnapshotPar (BOOL bHigh, BOOL bAutoMode)
{
        if (m_pSetSnapshotPar)
        {
                return m_pSetSnapshotPar (m_LSID, bHigh, bAutoMode);
        }
        else
                return -1;
}

int CLStep64::SetTrigger (BOOL bATrigger)
{
        if (m_pSetTrigger)
        {
                return m_pSetTrigger (m_LSID, bATrigger);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_ (int lATrigger)
{
        if (m_pSetTrigger_)
        {
                return m_pSetTrigger_ (m_LSID, lATrigger);
        }
        else
                return -1;
}

int CLStep64::SetTriggerPar (int lAxis, int lMode, int lSignal, double dDistance)
{
        if (m_pSetTriggerPar)
        {
                return m_pSetTriggerPar (m_LSID, lAxis, lMode, lSignal, dDistance);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoPar (int lAxis, int lMode, int lSignal, double dDistance)
{
        if (m_pSetTrigger_TwoPar)
        {
                return m_pSetTrigger_TwoPar (m_LSID, lAxis, lMode, lSignal, dDistance);
        }
        else
                return -1;
}

int CLStep64::SetTriggerSource (int lSource)
{
        if (m_pSetTriggerSource)
        {
                return m_pSetTriggerSource (m_LSID, lSource);
        }
        else
                return -1;
}

int CLStep64::GetTriggerSource (int *plSource)
{
        if (m_pGetTriggerSource)
        {
                return m_pGetTriggerSource (m_LSID, plSource);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoSource (int lSource)
{
        if (m_pSetTrigger_TwoSource)
        {
                return m_pSetTrigger_TwoSource (m_LSID, lSource);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoSource (int *plSource)
{
        if (m_pGetTrigger_TwoSource)
        {
                return m_pGetTrigger_TwoSource (m_LSID, plSource);
        }
        else
                return -1;
}

int CLStep64::SetTriggerHysterese (double dHysterese)
{
        if (m_pSetTriggerHysterese)
        {
                return m_pSetTriggerHysterese (m_LSID, dHysterese);
        }
        else
                return -1;
}

int CLStep64::GetTriggerHysterese (double *pdHysterese)
{
        if (m_pGetTriggerHysterese)
        {
                return m_pGetTriggerHysterese (m_LSID, pdHysterese);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoHysterese (double dHysterese)
{
        if (m_pSetTrigger_TwoHysterese)
        {
                return m_pSetTrigger_TwoHysterese (m_LSID, dHysterese);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoHysterese (double *pdHysterese)
{
        if (m_pGetTrigger_TwoHysterese)
        {
                return m_pGetTrigger_TwoHysterese (m_LSID, pdHysterese);
        }
        else
                return -1;
}

int CLStep64::SetTriggerPLength (int lLength)
{
        if (m_pSetTriggerPLength)
        {
                return m_pSetTriggerPLength (m_LSID, lLength);
        }
        else
                return -1;
}

int CLStep64::GetTriggerPLength (int *plLength)
{
        if (m_pGetTriggerPLength)
        {
                return m_pGetTriggerPLength (m_LSID, plLength);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoPLength (int lLength)
{
        if (m_pSetTrigger_TwoPLength)
        {
                return m_pSetTrigger_TwoPLength (m_LSID, lLength);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoPLength (int *plLength)
{
        if (m_pGetTrigger_TwoPLength)
        {
                return m_pGetTrigger_TwoPLength (m_LSID, plLength);
        }
        else
                return -1;
}

int CLStep64::SetTriggerPulsCount (int lCount)
{
        if (m_pSetTriggerPulsCount)
        {
                return m_pSetTriggerPulsCount (m_LSID, lCount);
        }
        else
                return -1;
}

int CLStep64::GetTriggerPulsCount (int *plCount)
{
        if (m_pGetTriggerPulsCount)
        {
                return m_pGetTriggerPulsCount (m_LSID, plCount);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoPulsCount (int lCount)
{
        if (m_pSetTrigger_TwoPulsCount)
        {
                return m_pSetTrigger_TwoPulsCount (m_LSID, lCount);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoPulsCount (int *plCount)
{
        if (m_pGetTrigger_TwoPulsCount)
        {
                return m_pGetTrigger_TwoPulsCount (m_LSID, plCount);
        }
        else
                return -1;
}

int CLStep64::SetConfigurated (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetConfigurated)
        {
                return m_pSetConfigurated (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetConfigurated (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetConfigurated)
        {
                return m_pGetConfigurated (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetStopMode (int lMode)
{
        if (m_pSetStopMode)
        {
                return m_pSetStopMode (m_LSID, lMode);
        }
        else
                return -1;
}

int CLStep64::GetStopMode (int *plMode)
{
        if (m_pGetStopMode)
        {
                return m_pGetStopMode (m_LSID, plMode);
        }
        else
                return -1;
}

int CLStep64::SetStopSwitchOffDelay  (int ldelay)
{
        if (m_pSetStopSwitchOffDelay )
        {
                return m_pSetStopSwitchOffDelay  (m_LSID, ldelay);
        }
        else
                return -1;
}

int CLStep64::GetStopSwitchOffDelay  (int *pldelay)
{
        if (m_pGetStopSwitchOffDelay )
        {
                return m_pGetStopSwitchOffDelay  (m_LSID, pldelay);
        }
        else
                return -1;
}

int CLStep64::SetLanguage (char *pcPLN)
{
        if (m_pSetLanguage)
        {
                return m_pSetLanguage (m_LSID, pcPLN);
        }
        else
                return -1;
}

int CLStep64::SetLanguageW (TCHAR *pcPLN)
{
        if (m_pSetLanguageW)
        {
                return m_pSetLanguageW (m_LSID, pcPLN);
        }
        else
                return -1;
}

int CLStep64::GetSwitches (int *plFlags)
{
        if (m_pGetSwitches)
        {
                return m_pGetSwitches (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::GetSerialNr (char *pcSerialNr, int lMaxLen)
{
        if (m_pGetSerialNr)
        {
                return m_pGetSerialNr (m_LSID, pcSerialNr, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetSerialNrW (TCHAR *pcSerialNr, int lMaxLen)
{
        if (m_pGetSerialNrW)
        {
                return m_pGetSerialNrW (m_LSID, pcSerialNr, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetCSOffset (double dX, double dY, double dZ, double dA)
{
        if (m_pSetCSOffset)
        {
                return m_pSetCSOffset (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetCSOffset (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetCSOffset)
        {
                return m_pGetCSOffset (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetCalibRMOffsetSWAct (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetCalibRMOffsetSWAct)
        {
                return m_pSetCalibRMOffsetSWAct (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetCalibRMOffsetSWAct (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetCalibRMOffsetSWAct)
        {
                return m_pGetCalibRMOffsetSWAct (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::MoveAbsV (double dX, double dY, double dZ, double dA, char *pcFeedback, int lMaxLen)
{
        if (m_pMoveAbsV)
        {
                return m_pMoveAbsV (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveAbsVW (double dX, double dY, double dZ, double dA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMoveAbsVW)
        {
                return m_pMoveAbsVW (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveRelV (double dX, double dY, double dZ, double dA, char *pcFeedback, int lMaxLen)
{
        if (m_pMoveRelV)
        {
                return m_pMoveRelV (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveRelVW (double dX, double dY, double dZ, double dA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMoveRelVW)
        {
                return m_pMoveRelVW (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetDeviationValue (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetDeviationValue)
        {
                return m_pGetDeviationValue (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetAutoKomm (char *pcFeedback, int lMaxLen)
{
        if (m_pSetAutoKomm)
        {
                return m_pSetAutoKomm (m_LSID, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetAutoKommW (TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pSetAutoKommW)
        {
                return m_pSetAutoKommW (m_LSID, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetAutoKomm (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetAutoKomm)
        {
                return m_pGetAutoKomm (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::GetAutoKommResult (double *pdX1, double *pdX2, double *pdY1, double *pdY2, double *pdZ1, double *pdZ2, double *pdA1, double *pdA2)
{
        if (m_pGetAutoKommResult)
        {
                return m_pGetAutoKommResult (m_LSID, pdX1, pdX2, pdY1, pdY2, pdZ1, pdZ2, pdA1, pdA2);
        }
        else
                return -1;
}

int CLStep64::SetTablePos (int lPosition, double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetTablePos)
        {
                return m_pSetTablePos (m_LSID, lPosition, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetTablePos (int lPosition, double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetTablePos)
        {
                return m_pGetTablePos (m_LSID, lPosition, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetIndexTableDivider (int lX, int lY, int lZ, int lA)
{
        if (m_pSetIndexTableDivider)
        {
                return m_pSetIndexTableDivider (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetIndexTableDivider (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetIndexTableDivider)
        {
                return m_pGetIndexTableDivider (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::MoveTablePosAbs (int lX, int lY, int lZ, int lA, char *pcFeedback, int lMaxLen)
{
        if (m_pMoveTablePosAbs)
        {
                return m_pMoveTablePosAbs (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveTablePosAbsW (int lX, int lY, int lZ, int lA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMoveTablePosAbsW)
        {
                return m_pMoveTablePosAbsW (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveTablePosRel (int lX, int lY, int lZ, int lA, char *pcFeedback, int lMaxLen)
{
        if (m_pMoveTablePosRel)
        {
                return m_pMoveTablePosRel (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveTablePosRelW (int lX, int lY, int lZ, int lA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMoveTablePosRelW)
        {
                return m_pMoveTablePosRelW (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveIndexTable (int lX, int lY, int lZ, int lA, char *pcFeedback, int lMaxLen)
{
        if (m_pMoveIndexTable)
        {
                return m_pMoveIndexTable (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MoveIndexTableW (int lX, int lY, int lZ, int lA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMoveIndexTableW)
        {
                return m_pMoveIndexTableW (m_LSID, lX, lY, lZ, lA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetSpeedEnable (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetSpeedEnable)
        {
                return m_pSetSpeedEnable (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedEnable (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetSpeedEnable)
        {
                return m_pGetSpeedEnable (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetSpeed (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeed)
        {
                return m_pSetSpeed (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeed (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeed)
        {
                return m_pGetSpeed (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetMixedMoveAxisMode (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMixedMoveAxisMode)
        {
                return m_pSetMixedMoveAxisMode (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMixedMoveAxisMode (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMixedMoveAxisMode)
        {
                return m_pGetMixedMoveAxisMode (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::MixedMoveAbs (double dX, double dY, double dZ, double dA, char *pcFeedback, int lMaxLen)
{
        if (m_pMixedMoveAbs)
        {
                return m_pMixedMoveAbs (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MixedMoveAbsW (double dX, double dY, double dZ, double dA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMixedMoveAbsW)
        {
                return m_pMixedMoveAbsW (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MixedMoveRel (double dX, double dY, double dZ, double dA, char *pcFeedback, int lMaxLen)
{
        if (m_pMixedMoveRel)
        {
                return m_pMixedMoveRel (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::MixedMoveRelW (double dX, double dY, double dZ, double dA, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pMixedMoveRelW)
        {
                return m_pMixedMoveRelW (m_LSID, dX, dY, dZ, dA, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetMixedMovePos (double dX, double dY, double dZ, double dA)
{
        if (m_pSetMixedMovePos)
        {
                return m_pSetMixedMovePos (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetMixedMovePos (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetMixedMovePos)
        {
                return m_pGetMixedMovePos (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetMixedMoveAmpl (double dX, double dY, double dZ, double dA)
{
        if (m_pSetMixedMoveAmpl)
        {
                return m_pSetMixedMoveAmpl (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetMixedMoveAmpl (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetMixedMoveAmpl)
        {
                return m_pGetMixedMoveAmpl (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetMoveSeqStatusPos (BOOL bstatus)
{
        if (m_pSetMoveSeqStatusPos)
        {
                return m_pSetMoveSeqStatusPos (m_LSID, bstatus);
        }
        else
                return -1;
}

int CLStep64::GetMoveSeqStatusPos (BOOL *pbstatus)
{
        if (m_pGetMoveSeqStatusPos)
        {
                return m_pGetMoveSeqStatusPos (m_LSID, pbstatus);
        }
        else
                return -1;
}

int CLStep64::SetMoveSeqStatus (int lstatus, char *pcFeedback, int lMaxLen)
{
        if (m_pSetMoveSeqStatus)
        {
                return m_pSetMoveSeqStatus (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetMoveSeqStatusW (int lstatus, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pSetMoveSeqStatusW)
        {
                return m_pSetMoveSeqStatusW (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetMoveSeqStatus (int *plstatus, int *plline)
{
        if (m_pGetMoveSeqStatus)
        {
                return m_pGetMoveSeqStatus (m_LSID, plstatus, plline);
        }
        else
                return -1;
}

int CLStep64::SetMoveSeqVar (double da, double db, double dc, double dd, double de)
{
        if (m_pSetMoveSeqVar)
        {
                return m_pSetMoveSeqVar (m_LSID, da, db, dc, dd, de);
        }
        else
                return -1;
}

int CLStep64::GetMoveSeqVar (double *pda, double *pdb, double *pdc, double *pdd, double *pde)
{
        if (m_pGetMoveSeqVar)
        {
                return m_pGetMoveSeqVar (m_LSID, pda, pdb, pdc, pdd, pde);
        }
        else
                return -1;
}

int CLStep64::SetCalibOffset (double dX, double dY, double dZ, double dA)
{
        if (m_pSetCalibOffset)
        {
                return m_pSetCalibOffset (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetRMOffset (double dX, double dY, double dZ, double dA)
{
        if (m_pSetRMOffset)
        {
                return m_pSetRMOffset (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetSnapshotPosArray (int lIndex, double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetSnapshotPosArray)
        {
                return m_pGetSnapshotPosArray (m_LSID, lIndex, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetAxisDirection (int lXD, int lYD, int lZD, int lAD)
{
        if (m_pSetAxisDirection)
        {
                return m_pSetAxisDirection (m_LSID, lXD, lYD, lZD, lAD);
        }
        else
                return -1;
}

int CLStep64::SetCalibrateDir (int lXD, int lYD, int lZD, int lAD)
{
        if (m_pSetCalibrateDir)
        {
                return m_pSetCalibrateDir (m_LSID, lXD, lYD, lZD, lAD);
        }
        else
                return -1;
}

int CLStep64::LStepSave ()
{
        if (m_pLStepSave)
        {
                return m_pLStepSave (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetBPZ (int lAValue)
{
        if (m_pSetBPZ)
        {
                return m_pSetBPZ (m_LSID, lAValue);
        }
        else
                return -1;
}

int CLStep64::SetBPZTrackballFactor (double dAValue)
{
        if (m_pSetBPZTrackballFactor)
        {
                return m_pSetBPZTrackballFactor (m_LSID, dAValue);
        }
        else
                return -1;
}

int CLStep64::SetBPZTrackballBackLash (double dX, double dY, double dZ, double dA)
{
        if (m_pSetBPZTrackballBackLash)
        {
                return m_pSetBPZTrackballBackLash (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetBPZJoyspeed (int lAPar, double dAValue)
{
        if (m_pSetBPZJoyspeed)
        {
                return m_pSetBPZJoyspeed (m_LSID, lAPar, dAValue);
        }
        else
                return -1;
}

int CLStep64::SetJoystickWindow (int lAValue)
{
        if (m_pSetJoystickWindow)
        {
                return m_pSetJoystickWindow (m_LSID, lAValue);
        }
        else
                return -1;
}

int CLStep64::SetCurrentDelay (int lX, int lY, int lZ, int lA)
{
        if (m_pSetCurrentDelay)
        {
                return m_pSetCurrentDelay (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::MoveEx (double dX, double dY, double dZ, double dA, BOOL bRelative, BOOL bWait, int lAxisCount)
{
        if (m_pMoveEx)
        {
                return m_pMoveEx (m_LSID, dX, dY, dZ, dA, bRelative, bWait, lAxisCount);
        }
        else
                return -1;
}

int CLStep64::WaitForAxisStop (int lAFlags, int lATimeoutValue, BOOL *pbATimeout)
{
        if (m_pWaitForAxisStop)
        {
                return m_pWaitForAxisStop (m_LSID, lAFlags, lATimeoutValue, pbATimeout);
        }
        else
                return -1;
}

int CLStep64::SendStringPosCmd (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut)
{
        if (m_pSendStringPosCmd)
        {
                return m_pSendStringPosCmd (m_LSID, pcStr, pcRet, lMaxLen, bReadLine, lTimeOut);
        }
        else
                return -1;
}

int CLStep64::SendStringPosCmdW (TCHAR *pcStr, TCHAR *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut)
{
        if (m_pSendStringPosCmdW)
        {
                return m_pSendStringPosCmdW (m_LSID, pcStr, pcRet, lMaxLen, bReadLine, lTimeOut);
        }
        else
                return -1;
}

int CLStep64::SetDigitalOutputs (int lValue)
{
        if (m_pSetDigitalOutputs)
        {
                return m_pSetDigitalOutputs (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::SetWriteLogTextFN (BOOL bAWriteLogText, char *pcALogFN)
{
        if (m_pSetWriteLogTextFN)
        {
                return m_pSetWriteLogTextFN (m_LSID, bAWriteLogText, pcALogFN);
        }
        else
                return -1;
}

int CLStep64::SetWriteLogTextFNW (BOOL bAWriteLogText, TCHAR *pcALogFN)
{
        if (m_pSetWriteLogTextFNW)
        {
                return m_pSetWriteLogTextFNW (m_LSID, bAWriteLogText, pcALogFN);
        }
        else
                return -1;
}

int CLStep64::EnableGlobalLogging (BOOL bAEnableGlobalLogging)
{
        if (m_pEnableGlobalLogging)
        {
                return m_pEnableGlobalLogging (m_LSID, bAEnableGlobalLogging);
        }
        else
                return -1;
}

int CLStep64::EnableGuiLogging (BOOL bAEnableGlobalLogging)
{
        if (m_pEnableGuiLogging)
        {
                return m_pEnableGuiLogging (m_LSID, bAEnableGlobalLogging);
        }
        else
                return -1;
}

int CLStep64::SetDigitalOutputsE (int lValue)
{
        if (m_pSetDigitalOutputsE)
        {
                return m_pSetDigitalOutputsE (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::SetDigOutLinktoSignal (int lOutput, int ltoSignal)
{
        if (m_pSetDigOutLinktoSignal)
        {
                return m_pSetDigOutLinktoSignal (m_LSID, lOutput, ltoSignal);
        }
        else
                return -1;
}

int CLStep64::GetDigOutLinktoSignal (int lOutput, int *pltoSignal)
{
        if (m_pGetDigOutLinktoSignal)
        {
                return m_pGetDigOutLinktoSignal (m_LSID, lOutput, pltoSignal);
        }
        else
                return -1;
}

int CLStep64::SetMonitoringVelFilter (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMonitoringVelFilter)
        {
                return m_pSetMonitoringVelFilter (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMonitoringVelFilter (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMonitoringVelFilter)
        {
                return m_pGetMonitoringVelFilter (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetHaltSignalVel (double dX, double dY, double dZ, double dA)
{
        if (m_pSetHaltSignalVel)
        {
                return m_pSetHaltSignalVel (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetHaltSignalVel (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetHaltSignalVel)
        {
                return m_pGetHaltSignalVel (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetThresholdSignalVel (double dX, double dY, double dZ, double dA)
{
        if (m_pSetThresholdSignalVel)
        {
                return m_pSetThresholdSignalVel (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetThresholdSignalVel (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetThresholdSignalVel)
        {
                return m_pGetThresholdSignalVel (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetInvertDigOutSignal (int lOutput, BOOL binvert)
{
        if (m_pSetInvertDigOutSignal)
        {
                return m_pSetInvertDigOutSignal (m_LSID, lOutput, binvert);
        }
        else
                return -1;
}

int CLStep64::GetInvertDigOutSignal (int lOutput, BOOL *pbinvert)
{
        if (m_pGetInvertDigOutSignal)
        {
                return m_pGetInvertDigOutSignal (m_LSID, lOutput, pbinvert);
        }
        else
                return -1;
}

int CLStep64::GetDigitalInputsE (int *plValue)
{
        if (m_pGetDigitalInputsE)
        {
                return m_pGetDigitalInputsE (m_LSID, plValue);
        }
        else
                return -1;
}

int CLStep64::EnableCommandRetry (BOOL bAValue)
{
        if (m_pEnableCommandRetry)
        {
                return m_pEnableCommandRetry (m_LSID, bAValue);
        }
        else
                return -1;
}

int CLStep64::SetXYAxisComp (int lValue)
{
        if (m_pSetXYAxisComp)
        {
                return m_pSetXYAxisComp (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::GetVersionStrDet (char *pcVersDet, int lMaxLen)
{
        if (m_pGetVersionStrDet)
        {
                return m_pGetVersionStrDet (m_LSID, pcVersDet, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetVersionStrDetW (TCHAR *pcVersDet, int lMaxLen)
{
        if (m_pGetVersionStrDetW)
        {
                return m_pGetVersionStrDetW (m_LSID, pcVersDet, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetAPIVersion (char *pcAPIVer, int lMaxLen)
{
        if (m_pGetAPIVersion)
        {
                return m_pGetAPIVersion (m_LSID, pcAPIVer, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetAPIVersionW (TCHAR *pcAPIVer, int lMaxLen)
{
        if (m_pGetAPIVersionW)
        {
                return m_pGetAPIVersionW (m_LSID, pcAPIVer, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetCommandTimeout (int lAtoRead, int lAtoMove, int lAtoCalibrate)
{
        if (m_pSetCommandTimeout)
        {
                return m_pSetCommandTimeout (m_LSID, lAtoRead, lAtoMove, lAtoCalibrate);
        }
        else
                return -1;
}

int CLStep64::SetExtValue (int lAName, int lAValue)
{
        if (m_pSetExtValue)
        {
                return m_pSetExtValue (m_LSID, lAName, lAValue);
        }
        else
                return -1;
}

int CLStep64::FlushBuffer (int lAValue)
{
        if (m_pFlushBuffer)
        {
                return m_pFlushBuffer (m_LSID, lAValue);
        }
        else
                return -1;
}

int CLStep64::SetProcessMessagesProc (void* pProc)
{
        if (m_pSetProcessMessagesProc)
        {
                return m_pSetProcessMessagesProc (m_LSID, pProc);
        }
        else
                return -1;
}

int CLStep64::GetEEPRomValue (byte Offset, byte *pValue)
{
        if (m_pGetEEPRomValue)
        {
                return m_pGetEEPRomValue (m_LSID, Offset, pValue);
        }
        else
                return -1;
}

int CLStep64::SetEEPRomValue (byte Offset, byte Value)
{
        if (m_pSetEEPRomValue)
        {
                return m_pSetEEPRomValue (m_LSID, Offset, Value);
        }
        else
                return -1;
}

int CLStep64::GetXYAxisComp (int *plValue)
{
        if (m_pGetXYAxisComp)
        {
                return m_pGetXYAxisComp (m_LSID, plValue);
        }
        else
                return -1;
}

int CLStep64::GetDimensions (int *plXD, int *plYD, int *plZD, int *plAD)
{
        if (m_pGetDimensions)
        {
                return m_pGetDimensions (m_LSID, plXD, plYD, plZD, plAD);
        }
        else
                return -1;
}

int CLStep64::GetPitch (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetPitch)
        {
                return m_pGetPitch (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetGear (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetGear)
        {
                return m_pGetGear (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetVel (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetVel)
        {
                return m_pGetVel (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetAccel (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetAccel)
        {
                return m_pGetAccel (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetVelFac (double dX, double dY, double dZ, double dA)
{
        if (m_pSetVelFac)
        {
                return m_pSetVelFac (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::SetVelFacSingleAxis (int lAxis, double dValue)
{
        if (m_pSetVelFacSingleAxis)
        {
                return m_pSetVelFacSingleAxis (m_LSID, lAxis, dValue);
        }
        else
                return -1;
}

int CLStep64::GetVelFac (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetVelFac)
        {
                return m_pGetVelFac (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedPoti (BOOL *pbSpePoti)
{
        if (m_pGetSpeedPoti)
        {
                return m_pGetSpeedPoti (m_LSID, pbSpePoti);
        }
        else
                return -1;
}

int CLStep64::GetMotorCurrent (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetMotorCurrent)
        {
                return m_pGetMotorCurrent (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetReduction (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetReduction)
        {
                return m_pGetReduction (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetCurrentDelay (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetCurrentDelay)
        {
                return m_pGetCurrentDelay (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetOutFuncLev (double dX, double dY, double dZ, double dA)
{
        if (m_pSetOutFuncLev)
        {
                return m_pSetOutFuncLev (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetOutFuncLev (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetOutFuncLev)
        {
                return m_pGetOutFuncLev (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetActiveAxes (int *plFlags)
{
        if (m_pGetActiveAxes)
        {
                return m_pGetActiveAxes (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::GetAxisDirection (int *plXD, int *plYD, int *plZD, int *plAD)
{
        if (m_pGetAxisDirection)
        {
                return m_pGetAxisDirection (m_LSID, plXD, plYD, plZD, plAD);
        }
        else
                return -1;
}

int CLStep64::GetCalibOffset (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetCalibOffset)
        {
                return m_pGetCalibOffset (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetRMOffset (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetRMOffset)
        {
                return m_pGetRMOffset (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetCalibrateDir (int *plXD, int *plYD, int *plZD, int *plAD)
{
        if (m_pGetCalibrateDir)
        {
                return m_pGetCalibrateDir (m_LSID, plXD, plYD, plZD, plAD);
        }
        else
                return -1;
}

int CLStep64::SetCalibBackSpeed (int lSpeed)
{
        if (m_pSetCalibBackSpeed)
        {
                return m_pSetCalibBackSpeed (m_LSID, lSpeed);
        }
        else
                return -1;
}

int CLStep64::GetCalibBackSpeed (int *plSpeed)
{
        if (m_pGetCalibBackSpeed)
        {
                return m_pGetCalibBackSpeed (m_LSID, plSpeed);
        }
        else
                return -1;
}

int CLStep64::SetRefSpeed (int lSpeed)
{
        if (m_pSetRefSpeed)
        {
                return m_pSetRefSpeed (m_LSID, lSpeed);
        }
        else
                return -1;
}

int CLStep64::GetRefSpeed (int *plSpeed)
{
        if (m_pGetRefSpeed)
        {
                return m_pGetRefSpeed (m_LSID, plSpeed);
        }
        else
                return -1;
}

int CLStep64::SetPowerAmplifier (BOOL bAmplifier)
{
        if (m_pSetPowerAmplifier)
        {
                return m_pSetPowerAmplifier (m_LSID, bAmplifier);
        }
        else
                return -1;
}

int CLStep64::GetPowerAmplifier (BOOL *pbAmplifier)
{
        if (m_pGetPowerAmplifier)
        {
                return m_pGetPowerAmplifier (m_LSID, pbAmplifier);
        }
        else
                return -1;
}

int CLStep64::ValidConfig (int lAxisInt)
{
        if (m_pValidConfig)
        {
                return m_pValidConfig (m_LSID, lAxisInt);
        }
        else
                return -1;
}

int CLStep64::ValidPar (int lAxisInt)
{
        if (m_pValidPar)
        {
                return m_pValidPar (m_LSID, lAxisInt);
        }
        else
                return -1;
}

int CLStep64::SetEqepConfig (int lWert)
{
        if (m_pSetEqepConfig)
        {
                return m_pSetEqepConfig (m_LSID, lWert);
        }
        else
                return -1;
}

int CLStep64::GetEqepConfig (int *plGetWert)
{
        if (m_pGetEqepConfig)
        {
                return m_pGetEqepConfig (m_LSID, plGetWert);
        }
        else
                return -1;
}

int CLStep64::SetTTLOutConfig (int lTTLOut)
{
        if (m_pSetTTLOutConfig)
        {
                return m_pSetTTLOutConfig (m_LSID, lTTLOut);
        }
        else
                return -1;
}

int CLStep64::GetTTLOutConfig (int *plTTLOut)
{
        if (m_pGetTTLOutConfig)
        {
                return m_pGetTTLOutConfig (m_LSID, plTTLOut);
        }
        else
                return -1;
}

int CLStep64::SetPoscon (BOOL bEnable)
{
        if (m_pSetPoscon)
        {
                return m_pSetPoscon (m_LSID, bEnable);
        }
        else
                return -1;
}

int CLStep64::GetPoscon (BOOL *pbEnable)
{
        if (m_pGetPoscon)
        {
                return m_pGetPoscon (m_LSID, pbEnable);
        }
        else
                return -1;
}

int CLStep64::SetManModePreselection (int lMMode)
{
        if (m_pSetManModePreselection)
        {
                return m_pSetManModePreselection (m_LSID, lMMode);
        }
        else
                return -1;
}

int CLStep64::GetManModePreselection (int *plMMode)
{
        if (m_pGetManModePreselection)
        {
                return m_pGetManModePreselection (m_LSID, plMMode);
        }
        else
                return -1;
}

int CLStep64::GetManModeLinktoAxisX (AnsiChar *pLink2)
{
        if (m_pGetManModeLinktoAxisX)
        {
                return m_pGetManModeLinktoAxisX (m_LSID, pLink2);
        }
        else
                return -1;
}

int CLStep64::GetManModeLinktoAxisY (AnsiChar *pLink2)
{
        if (m_pGetManModeLinktoAxisY)
        {
                return m_pGetManModeLinktoAxisY (m_LSID, pLink2);
        }
        else
                return -1;
}

int CLStep64::GetManModeLinktoAxisZ (AnsiChar *pLink2)
{
        if (m_pGetManModeLinktoAxisZ)
        {
                return m_pGetManModeLinktoAxisZ (m_LSID, pLink2);
        }
        else
                return -1;
}

int CLStep64::GetManModeLinktoAxisA (AnsiChar *pLink2)
{
        if (m_pGetManModeLinktoAxisA)
        {
                return m_pGetManModeLinktoAxisA (m_LSID, pLink2);
        }
        else
                return -1;
}

int CLStep64::SetJoyRedCur (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetJoyRedCur)
        {
                return m_pSetJoyRedCur (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::SetAnaOutPreset (int lOutput, int lStartValue)
{
        if (m_pSetAnaOutPreset)
        {
                return m_pSetAnaOutPreset (m_LSID, lOutput, lStartValue);
        }
        else
                return -1;
}

int CLStep64::GetAnaOutPreset (int *plOutput1, int *plOutput2)
{
        if (m_pGetAnaOutPreset)
        {
                return m_pGetAnaOutPreset (m_LSID, plOutput1, plOutput2);
        }
        else
                return -1;
}

int CLStep64::GetJoyRedCur (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetJoyRedCur)
        {
                return m_pGetJoyRedCur (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetJoytoAxis (int lX, int lY, int lZ, int lR)
{
        if (m_pSetJoytoAxis)
        {
                return m_pSetJoytoAxis (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetJoytoAxis (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetJoytoAxis)
        {
                return m_pGetJoytoAxis (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetTipp (BOOL bTipp)
{
        if (m_pSetTipp)
        {
                return m_pSetTipp (m_LSID, bTipp);
        }
        else
                return -1;
}

int CLStep64::GetTipp (BOOL *pbTipp)
{
        if (m_pGetTipp)
        {
                return m_pGetTipp (m_LSID, pbTipp);
        }
        else
                return -1;
}

int CLStep64::SetTippEnable (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetTippEnable)
        {
                return m_pSetTippEnable (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetTippEnable (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetTippEnable)
        {
                return m_pGetTippEnable (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetTippRedCur (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetTippRedCur)
        {
                return m_pSetTippRedCur (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetTippRedCur (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetTippRedCur)
        {
                return m_pGetTippRedCur (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetTippVel (double dX, double dY, double dZ, double dR)
{
        if (m_pSetTippVel)
        {
                return m_pSetTippVel (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetTippVel (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetTippVel)
        {
                return m_pGetTippVel (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetTippDir (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetTippDir)
        {
                return m_pSetTippDir (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetTippDir (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetTippDir)
        {
                return m_pGetTippDir (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetModulo (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetModulo)
        {
                return m_pSetModulo (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetModulo (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetModulo)
        {
                return m_pGetModulo (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetModuloMode (int lX, int lY, int lZ, int lR)
{
        if (m_pSetModuloMode)
        {
                return m_pSetModuloMode (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetModuloMode (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetModuloMode)
        {
                return m_pGetModuloMode (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetEncDir (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetEncDir)
        {
                return m_pSetEncDir (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetEncDir (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetEncDir)
        {
                return m_pGetEncDir (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetEncPolePairs (int lX, int lY, int lZ, int lR)
{
        if (m_pSetEncPolePairs)
        {
                return m_pSetEncPolePairs (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetEncPolePairs (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetEncPolePairs)
        {
                return m_pGetEncPolePairs (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetEnctoAxis (int lX, int lY, int lZ, int lR)
{
        if (m_pSetEnctoAxis)
        {
                return m_pSetEnctoAxis (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetEnctoAxis (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetEnctoAxis)
        {
                return m_pGetEnctoAxis (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetEncType (int lX, int lY, int lZ, int lR)
{
        if (m_pSetEncType)
        {
                return m_pSetEncType (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetEncType (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetEncType)
        {
                return m_pGetEncType (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotortempSensor (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetMotortempSensor)
        {
                return m_pSetMotortempSensor (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetMotortempSensor (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetMotortempSensor)
        {
                return m_pGetMotortempSensor (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetMotortempSensormin (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotortempSensormin)
        {
                return m_pSetMotortempSensormin (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotortempSensormin (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotortempSensormin)
        {
                return m_pGetMotortempSensormin (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotortempSensormax (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotortempSensormax)
        {
                return m_pSetMotortempSensormax (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotortempSensormax (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotortempSensormax)
        {
                return m_pGetMotortempSensormax (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::GetMotortempSensorValue (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotortempSensorValue)
        {
                return m_pGetMotortempSensorValue (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetKommMode (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetKommMode)
        {
                return m_pSetKommMode (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetKommMode (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetKommMode)
        {
                return m_pGetKommMode (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetKommEncDir (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetKommEncDir)
        {
                return m_pSetKommEncDir (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetKommEncDir (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetKommEncDir)
        {
                return m_pGetKommEncDir (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetKommEncPolePairs (int lX, int lY, int lZ, int lR)
{
        if (m_pSetKommEncPolePairs)
        {
                return m_pSetKommEncPolePairs (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetKommEncPolePairs (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetKommEncPolePairs)
        {
                return m_pGetKommEncPolePairs (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetKommEnctoAxis (int lX, int lY, int lZ, int lR)
{
        if (m_pSetKommEnctoAxis)
        {
                return m_pSetKommEnctoAxis (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetKommEnctoAxis (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetKommEnctoAxis)
        {
                return m_pGetKommEnctoAxis (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetKommEncType (int lX, int lY, int lZ, int lR)
{
        if (m_pSetKommEncType)
        {
                return m_pSetKommEncType (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetKommEncType (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetKommEncType)
        {
                return m_pGetKommEncType (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorPolePairs (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotorPolePairs)
        {
                return m_pSetMotorPolePairs (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotorPolePairs (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotorPolePairs)
        {
                return m_pGetMotorPolePairs (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorPolePairRes (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotorPolePairRes)
        {
                return m_pSetMotorPolePairRes (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotorPolePairRes (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotorPolePairRes)
        {
                return m_pGetMotorPolePairRes (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorPoleScale (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorPoleScale)
        {
                return m_pSetMotorPoleScale (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorPoleScale (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorPoleScale)
        {
                return m_pGetMotorPoleScale (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::GetSysStat (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetSysStat)
        {
                return m_pGetSysStat (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::GetSysStatusW (TCHAR *pcStatus, int lMaxLen)
{
        if (m_pGetSysStatusW)
        {
                return m_pGetSysStatusW (m_LSID, pcStatus, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetSysStatus (char *pcStatus, int lMaxLen)
{
        if (m_pGetSysStatus)
        {
                return m_pGetSysStatus (m_LSID, pcStatus, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStopStatus (Boolean *pStopStatus)
{
        if (m_pGetStopStatus)
        {
                return m_pGetStopStatus (m_LSID, pStopStatus);
        }
        else
                return -1;
}

int CLStep64::Quit ()
{
        if (m_pQuit)
        {
                return m_pQuit (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetMotorBrakeSwitchOnDelay (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotorBrakeSwitchOnDelay)
        {
                return m_pSetMotorBrakeSwitchOnDelay (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotorBrakeSwitchOnDelay (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotorBrakeSwitchOnDelay)
        {
                return m_pGetMotorBrakeSwitchOnDelay (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorBrakeSwitchOffDelay (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotorBrakeSwitchOffDelay)
        {
                return m_pSetMotorBrakeSwitchOffDelay (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotorBrakeSwitchOffDelay (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotorBrakeSwitchOffDelay)
        {
                return m_pGetMotorBrakeSwitchOffDelay (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorAutoKommDelay (int lX, int lY, int lZ, int lR)
{
        if (m_pSetMotorAutoKommDelay)
        {
                return m_pSetMotorAutoKommDelay (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetMotorAutoKommDelay (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetMotorAutoKommDelay)
        {
                return m_pGetMotorAutoKommDelay (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetMotorAutoKommSpeedScale (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorAutoKommSpeedScale)
        {
                return m_pSetMotorAutoKommSpeedScale (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorAutoKommSpeedScale (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorAutoKommSpeedScale)
        {
                return m_pGetMotorAutoKommSpeedScale (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetMotorForceConstant (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorForceConstant)
        {
                return m_pSetMotorForceConstant (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorForceConstant (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorForceConstant)
        {
                return m_pGetMotorForceConstant (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetMotorLoad (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorLoad)
        {
                return m_pSetMotorLoad (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorLoad (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorLoad)
        {
                return m_pGetMotorLoad (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetMotorMomentConstant (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorMomentConstant)
        {
                return m_pSetMotorMomentConstant (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorMomentConstant (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorMomentConstant)
        {
                return m_pGetMotorMomentConstant (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetMotorMomentOfInertia (double dX, double dY, double dZ, double dR)
{
        if (m_pSetMotorMomentOfInertia)
        {
                return m_pSetMotorMomentOfInertia (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetMotorMomentOfInertia (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetMotorMomentOfInertia)
        {
                return m_pGetMotorMomentOfInertia (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetPosConKP (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConKP)
        {
                return m_pSetPosConKP (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConKP (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConKP)
        {
                return m_pGetPosConKP (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConAdaptiveKP (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConAdaptiveKP)
        {
                return m_pSetPosConAdaptiveKP (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConAdaptiveKP (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConAdaptiveKP)
        {
                return m_pGetPosConAdaptiveKP (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConKI (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConKI)
        {
                return m_pSetPosConKI (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConKI (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConKI)
        {
                return m_pGetPosConKI (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConAdaptiveKI (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConAdaptiveKI)
        {
                return m_pSetPosConAdaptiveKI (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConAdaptiveKI (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConAdaptiveKI)
        {
                return m_pGetPosConAdaptiveKI (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConOutPass)
        {
                return m_pSetPosConOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConOutPass)
        {
                return m_pGetPosConOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConAdaptiveOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConAdaptiveOutPass)
        {
                return m_pSetPosConAdaptiveOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConAdaptiveOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConAdaptiveOutPass)
        {
                return m_pGetPosConAdaptiveOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConEnable (int lX, int lY, int lZ, int lA)
{
        if (m_pSetPosConEnable)
        {
                return m_pSetPosConEnable (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetPosConEnable (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetPosConEnable)
        {
                return m_pGetPosConEnable (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetSpeedConKP (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeedConKP)
        {
                return m_pSetSpeedConKP (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedConKP (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeedConKP)
        {
                return m_pGetSpeedConKP (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetSpeedConKI (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeedConKI)
        {
                return m_pSetSpeedConKI (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedConKI (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeedConKI)
        {
                return m_pGetSpeedConKI (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetSpeedConKD (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeedConKD)
        {
                return m_pSetSpeedConKD (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedConKD (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeedConKD)
        {
                return m_pGetSpeedConKD (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetSpeedConOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeedConOutPass)
        {
                return m_pSetSpeedConOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedConOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeedConOutPass)
        {
                return m_pGetSpeedConOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosConNominalSpeed (double dX, double dY, double dZ, double dA)
{
        if (m_pSetPosConNominalSpeed)
        {
                return m_pSetPosConNominalSpeed (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetPosConNominalSpeed (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetPosConNominalSpeed)
        {
                return m_pGetPosConNominalSpeed (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetPosConAdaptiveSpeed (double dX, double dY, double dZ, double dA)
{
        if (m_pSetPosConAdaptiveSpeed)
        {
                return m_pSetPosConAdaptiveSpeed (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetPosConAdaptiveSpeed (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetPosConAdaptiveSpeed)
        {
                return m_pGetPosConAdaptiveSpeed (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetActSpeedFilterConst (int lX, int lY, int lZ, int lA)
{
        if (m_pSetActSpeedFilterConst)
        {
                return m_pSetActSpeedFilterConst (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetActSpeedFilterConst (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetActSpeedFilterConst)
        {
                return m_pGetActSpeedFilterConst (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetSpeedFeedForward (int lX, int lY, int lZ, int lA)
{
        if (m_pSetSpeedFeedForward)
        {
                return m_pSetSpeedFeedForward (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedFeedForward (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetSpeedFeedForward)
        {
                return m_pGetSpeedFeedForward (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetActAccelFilterConst (int lX, int lY, int lZ, int lA)
{
        if (m_pSetActAccelFilterConst)
        {
                return m_pSetActAccelFilterConst (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetActAccelFilterConst (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetActAccelFilterConst)
        {
                return m_pGetActAccelFilterConst (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetAccelFeedForward (int lX, int lY, int lZ, int lA)
{
        if (m_pSetAccelFeedForward)
        {
                return m_pSetAccelFeedForward (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetAccelFeedForward (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetAccelFeedForward)
        {
                return m_pGetAccelFeedForward (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetAccelFeedForwardOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetAccelFeedForwardOutPass)
        {
                return m_pSetAccelFeedForwardOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetAccelFeedForwardOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetAccelFeedForwardOutPass)
        {
                return m_pGetAccelFeedForwardOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetPosMode (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetPosMode)
        {
                return m_pSetPosMode (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetPosMode (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetPosMode)
        {
                return m_pGetPosMode (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::GetSpeedConTN (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetSpeedConTN)
        {
                return m_pGetSpeedConTN (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetPowerAmplifierStatus (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetPowerAmplifierStatus)
        {
                return m_pGetPowerAmplifierStatus (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::GetPTemp (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetPTemp)
        {
                return m_pGetPTemp (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetSysSampleRate (int lrate)
{
        if (m_pSetSysSampleRate)
        {
                return m_pSetSysSampleRate (m_LSID, lrate);
        }
        else
                return -1;
}

int CLStep64::GetSysSampleRate (int *plrate)
{
        if (m_pGetSysSampleRate)
        {
                return m_pGetSysSampleRate (m_LSID, plrate);
        }
        else
                return -1;
}

int CLStep64::SetAxisMap (int lX, int lY, int lZ, int lR)
{
        if (m_pSetAxisMap)
        {
                return m_pSetAxisMap (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetAxisMap (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetAxisMap)
        {
                return m_pGetAxisMap (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetBaud (int lrate)
{
        if (m_pSetBaud)
        {
                return m_pSetBaud (m_LSID, lrate);
        }
        else
                return -1;
}

int CLStep64::GetBaud (int *plrate)
{
        if (m_pGetBaud)
        {
                return m_pGetBaud (m_LSID, plrate);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_Two (int lStatus)
{
        if (m_pSetTrigger_Two)
        {
                return m_pSetTrigger_Two (m_LSID, lStatus);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_Two (int *plStatus)
{
        if (m_pGetTrigger_Two)
        {
                return m_pGetTrigger_Two (m_LSID, plStatus);
        }
        else
                return -1;
}

int CLStep64::SetTriggerDim (int lDimension)
{
        if (m_pSetTriggerDim)
        {
                return m_pSetTriggerDim (m_LSID, lDimension);
        }
        else
                return -1;
}

int CLStep64::GetTriggerDim (int *plDimension)
{
        if (m_pGetTriggerDim)
        {
                return m_pGetTriggerDim (m_LSID, plDimension);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoDim (int lDimension)
{
        if (m_pSetTrigger_TwoDim)
        {
                return m_pSetTrigger_TwoDim (m_LSID, lDimension);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoDim (int *plDimension)
{
        if (m_pGetTrigger_TwoDim)
        {
                return m_pGetTrigger_TwoDim (m_LSID, plDimension);
        }
        else
                return -1;
}

int CLStep64::SetPosWindowRange (double dX, double dY, double dZ, double dR)
{
        if (m_pSetPosWindowRange)
        {
                return m_pSetPosWindowRange (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetPosWindowRange (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetPosWindowRange)
        {
                return m_pGetPosWindowRange (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetPosWindowTime (int lX, int lY, int lZ, int lR)
{
        if (m_pSetPosWindowTime)
        {
                return m_pSetPosWindowTime (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetPosWindowTime (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetPosWindowTime)
        {
                return m_pGetPosWindowTime (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetPosWindowTimeout (int lX, int lY, int lZ, int lR)
{
        if (m_pSetPosWindowTimeout)
        {
                return m_pSetPosWindowTimeout (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetPosWindowTimeout (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetPosWindowTimeout)
        {
                return m_pGetPosWindowTimeout (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetPosWindowCheck (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetPosWindowCheck)
        {
                return m_pSetPosWindowCheck (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetPosWindowCheck (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetPosWindowCheck)
        {
                return m_pGetPosWindowCheck (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetDeviationRange (double dX, double dY, double dZ, double dR)
{
        if (m_pSetDeviationRange)
        {
                return m_pSetDeviationRange (m_LSID, dX, dY, dZ, dR);
        }
        else
                return -1;
}

int CLStep64::GetDeviationRange (double *pdX, double *pdY, double *pdZ, double *pdR)
{
        if (m_pGetDeviationRange)
        {
                return m_pGetDeviationRange (m_LSID, pdX, pdY, pdZ, pdR);
        }
        else
                return -1;
}

int CLStep64::SetDeviationTime (int lX, int lY, int lZ, int lR)
{
        if (m_pSetDeviationTime)
        {
                return m_pSetDeviationTime (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetDeviationTime (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetDeviationTime)
        {
                return m_pGetDeviationTime (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetDeviationCheck (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetDeviationCheck)
        {
                return m_pSetDeviationCheck (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::GetDeviationCheck (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbR)
{
        if (m_pGetDeviationCheck)
        {
                return m_pGetDeviationCheck (m_LSID, pbX, pbY, pbZ, pbR);
        }
        else
                return -1;
}

int CLStep64::SetHalt (BOOL bX, BOOL bY, BOOL bZ, BOOL bR)
{
        if (m_pSetHalt)
        {
                return m_pSetHalt (m_LSID, bX, bY, bZ, bR);
        }
        else
                return -1;
}

int CLStep64::SetMotorTablePatch (BOOL bActive)
{
        if (m_pSetMotorTablePatch)
        {
                return m_pSetMotorTablePatch (m_LSID, bActive);
        }
        else
                return -1;
}

int CLStep64::GetMotorTablePatch (BOOL *pbActive)
{
        if (m_pGetMotorTablePatch)
        {
                return m_pGetMotorTablePatch (m_LSID, pbActive);
        }
        else
                return -1;
}

int CLStep64::SetJoystickFilter (BOOL bActive)
{
        if (m_pSetJoystickFilter)
        {
                return m_pSetJoystickFilter (m_LSID, bActive);
        }
        else
                return -1;
}

int CLStep64::GetJoystickFilter (BOOL *pbActive)
{
        if (m_pGetJoystickFilter)
        {
                return m_pGetJoystickFilter (m_LSID, pbActive);
        }
        else
                return -1;
}

int CLStep64::SetStopPolarity (BOOL bHighActiv)
{
        if (m_pSetStopPolarity)
        {
                return m_pSetStopPolarity (m_LSID, bHighActiv);
        }
        else
                return -1;
}

int CLStep64::GetStopPolarity (BOOL *pbHighActiv)
{
        if (m_pGetStopPolarity)
        {
                return m_pGetStopPolarity (m_LSID, pbHighActiv);
        }
        else
                return -1;
}

int CLStep64::SetVLevel (int lVRegion, double dDownLevel, double dUpLevel)
{
        if (m_pSetVLevel)
        {
                return m_pSetVLevel (m_LSID, lVRegion, dDownLevel, dUpLevel);
        }
        else
                return -1;
}

int CLStep64::GetVLevel (int lVRegion, double *pdDownLevel, double *pdUpLevel)
{
        if (m_pGetVLevel)
        {
                return m_pGetVLevel (m_LSID, lVRegion, pdDownLevel, pdUpLevel);
        }
        else
                return -1;
}

int CLStep64::SetStopAccel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetStopAccel)
        {
                return m_pSetStopAccel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetStopAccel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetStopAccel)
        {
                return m_pGetStopAccel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::GetVersionStrInfo (char *pcVersInfo, int lMaxLen)
{
        if (m_pGetVersionStrInfo)
        {
                return m_pGetVersionStrInfo (m_LSID, pcVersInfo, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetVersionStrInfoW (TCHAR *pcVersInfo, int lMaxLen)
{
        if (m_pGetVersionStrInfoW)
        {
                return m_pGetVersionStrInfoW (m_LSID, pcVersInfo, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStatusLimit (char *pcLimit, int lMaxLen)
{
        if (m_pGetStatusLimit)
        {
                return m_pGetStatusLimit (m_LSID, pcLimit, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStatusLimitW (TCHAR *pcLimit, int lMaxLen)
{
        if (m_pGetStatusLimitW)
        {
                return m_pGetStatusLimitW (m_LSID, pcLimit, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetSecurityErr (DWORD *pdwValue)
{
        if (m_pGetSecurityErr)
        {
                return m_pGetSecurityErr (m_LSID, pdwValue);
        }
        else
                return -1;
}

int CLStep64::GetSecurityStatus (DWORD *pdwValue)
{
        if (m_pGetSecurityStatus)
        {
                return m_pGetSecurityStatus (m_LSID, pdwValue);
        }
        else
                return -1;
}

int CLStep64::GetDelay (int *plDelay)
{
        if (m_pGetDelay)
        {
                return m_pGetDelay (m_LSID, plDelay);
        }
        else
                return -1;
}

int CLStep64::GetDistance (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetDistance)
        {
                return m_pGetDistance (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::ClearPos (int lFlags)
{
        if (m_pClearPos)
        {
                return m_pClearPos (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::SetDigJoySpeed (double dX, double dY, double dZ, double dA)
{
        if (m_pSetDigJoySpeed)
        {
                return m_pSetDigJoySpeed (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetDigJoySpeed (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetDigJoySpeed)
        {
                return m_pGetDigJoySpeed (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetJoystickDir (int *plXD, int *plYD, int *plZD, int *plAD)
{
        if (m_pGetJoystickDir)
        {
                return m_pGetJoystickDir (m_LSID, plXD, plYD, plZD, plAD);
        }
        else
                return -1;
}

int CLStep64::GetJoystick (BOOL *pbJoystickOn, BOOL *pbManual, BOOL *pbPositionCount, BOOL *pbEncoder)
{
        if (m_pGetJoystick)
        {
                return m_pGetJoystick (m_LSID, pbJoystickOn, pbManual, pbPositionCount, pbEncoder);
        }
        else
                return -1;
}

int CLStep64::GetJoystickWindow (int *plAValue)
{
        if (m_pGetJoystickWindow)
        {
                return m_pGetJoystickWindow (m_LSID, plAValue);
        }
        else
                return -1;
}

int CLStep64::GetHandWheel (BOOL *pbHandWheelOn, BOOL *pbPositionCount, BOOL *pbEncoder)
{
        if (m_pGetHandWheel)
        {
                return m_pGetHandWheel (m_LSID, pbHandWheelOn, pbPositionCount, pbEncoder);
        }
        else
                return -1;
}

int CLStep64::GetBPZ (int *plAValue)
{
        if (m_pGetBPZ)
        {
                return m_pGetBPZ (m_LSID, plAValue);
        }
        else
                return -1;
}

int CLStep64::GetBPZTrackballFactor (double *pdAValue)
{
        if (m_pGetBPZTrackballFactor)
        {
                return m_pGetBPZTrackballFactor (m_LSID, pdAValue);
        }
        else
                return -1;
}

int CLStep64::GetBPZTrackballBackLash (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetBPZTrackballBackLash)
        {
                return m_pGetBPZTrackballBackLash (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetBPZJoyspeed (int lAPar, double *pdAValue)
{
        if (m_pGetBPZJoyspeed)
        {
                return m_pGetBPZJoyspeed (m_LSID, lAPar, pdAValue);
        }
        else
                return -1;
}

int CLStep64::GetLimitControl (int lAxis, BOOL *pbActive)
{
        if (m_pGetLimitControl)
        {
                return m_pGetLimitControl (m_LSID, lAxis, pbActive);
        }
        else
                return -1;
}

int CLStep64::SetAutoLimitAfterCalibRM (int lFlags)
{
        if (m_pSetAutoLimitAfterCalibRM)
        {
                return m_pSetAutoLimitAfterCalibRM (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::GetAutoLimitAfterCalibRM (int *plFlags)
{
        if (m_pGetAutoLimitAfterCalibRM)
        {
                return m_pGetAutoLimitAfterCalibRM (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::GetSwitchPolarity (int *plXP, int *plYP, int *plZP, int *plAP)
{
        if (m_pGetSwitchPolarity)
        {
                return m_pGetSwitchPolarity (m_LSID, plXP, plYP, plZP, plAP);
        }
        else
                return -1;
}

int CLStep64::GetSwitchActive (int *plXA, int *plYA, int *plZA, int *plAA)
{
        if (m_pGetSwitchActive)
        {
                return m_pGetSwitchActive (m_LSID, plXA, plYA, plZA, plAA);
        }
        else
                return -1;
}

int CLStep64::GetTVRMode (int *plXT, int *plYT, int *plZT, int *plAT)
{
        if (m_pGetTVRMode)
        {
                return m_pGetTVRMode (m_LSID, plXT, plYT, plZT, plAT);
        }
        else
                return -1;
}

int CLStep64::GetFactorTVR (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetFactorTVR)
        {
                return m_pGetFactorTVR (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetTVROutMode (int lXT, int lYT, int lZT, int lAT)
{
        if (m_pSetTVROutMode)
        {
                return m_pSetTVROutMode (m_LSID, lXT, lYT, lZT, lAT);
        }
        else
                return -1;
}

int CLStep64::GetTVROutMode (int *plXT, int *plYT, int *plZT, int *plAT)
{
        if (m_pGetTVROutMode)
        {
                return m_pGetTVROutMode (m_LSID, plXT, plYT, plZT, plAT);
        }
        else
                return -1;
}

int CLStep64::SetTVROutResolution (int lX, int lY, int lZ, int lA)
{
        if (m_pSetTVROutResolution)
        {
                return m_pSetTVROutResolution (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetTVROutResolution (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetTVROutResolution)
        {
                return m_pGetTVROutResolution (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetTVROutPitch (double dX, double dY, double dZ, double dA)
{
        if (m_pSetTVROutPitch)
        {
                return m_pSetTVROutPitch (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetTVROutPitch (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetTVROutPitch)
        {
                return m_pGetTVROutPitch (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetVelTVRO (double dX, double dY, double dZ, double dA)
{
        if (m_pSetVelTVRO)
        {
                return m_pSetVelTVRO (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetVelTVRO (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetVelTVRO)
        {
                return m_pGetVelTVRO (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetAccelTVRO (double dX, double dY, double dZ, double dA)
{
        if (m_pSetAccelTVRO)
        {
                return m_pSetAccelTVRO (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetAccelTVRO (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetAccelTVRO)
        {
                return m_pGetAccelTVRO (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetVelSingleAxisTVRO (int lAxis, double dVel)
{
        if (m_pSetVelSingleAxisTVRO)
        {
                return m_pSetVelSingleAxisTVRO (m_LSID, lAxis, dVel);
        }
        else
                return -1;
}

int CLStep64::SetAccelSingleAxisTVRO (int lAxis, double dAccel)
{
        if (m_pSetAccelSingleAxisTVRO)
        {
                return m_pSetAccelSingleAxisTVRO (m_LSID, lAxis, dAccel);
        }
        else
                return -1;
}

int CLStep64::SetPosTVRO (double dX, double dY, double dZ, double dA)
{
        if (m_pSetPosTVRO)
        {
                return m_pSetPosTVRO (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetPosTVRO (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetPosTVRO)
        {
                return m_pGetPosTVRO (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::MoveAbsTVRO (double dX, double dY, double dZ, double dA, BOOL bWait)
{
        if (m_pMoveAbsTVRO)
        {
                return m_pMoveAbsTVRO (m_LSID, dX, dY, dZ, dA, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveRelTVRO (double dX, double dY, double dZ, double dA, BOOL bWait)
{
        if (m_pMoveRelTVRO)
        {
                return m_pMoveRelTVRO (m_LSID, dX, dY, dZ, dA, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveRelTVROSingleAxis (int lAxis, double dValue, BOOL bWait)
{
        if (m_pMoveRelTVROSingleAxis)
        {
                return m_pMoveRelTVROSingleAxis (m_LSID, lAxis, dValue, bWait);
        }
        else
                return -1;
}

int CLStep64::MoveAbsTVROSingleAxis (int lAxis, double dValue, BOOL bWait)
{
        if (m_pMoveAbsTVROSingleAxis)
        {
                return m_pMoveAbsTVROSingleAxis (m_LSID, lAxis, dValue, bWait);
        }
        else
                return -1;
}

int CLStep64::GetStatusTVRO (char *pcStat, int lMaxLen)
{
        if (m_pGetStatusTVRO)
        {
                return m_pGetStatusTVRO (m_LSID, pcStat, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetStatusTVROW (TCHAR *pcStat, int lMaxLen)
{
        if (m_pGetStatusTVROW)
        {
                return m_pGetStatusTVROW (m_LSID, pcStat, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetTargetWindow (double dX, double dY, double dZ, double dA)
{
        if (m_pSetTargetWindow)
        {
                return m_pSetTargetWindow (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetTargetWindow (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetTargetWindow)
        {
                return m_pGetTargetWindow (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetEncoderPeriod (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetEncoderPeriod)
        {
                return m_pGetEncoderPeriod (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetEncoderRefSignal (int *plXR, int *plYR, int *plZR, int *plAR)
{
        if (m_pGetEncoderRefSignal)
        {
                return m_pGetEncoderRefSignal (m_LSID, plXR, plYR, plZR, plAR);
        }
        else
                return -1;
}

int CLStep64::GetEncoderPosition (BOOL *pbValue)
{
        if (m_pGetEncoderPosition)
        {
                return m_pGetEncoderPosition (m_LSID, pbValue);
        }
        else
                return -1;
}

int CLStep64::GetEncoderActive (int *plFlags)
{
        if (m_pGetEncoderActive)
        {
                return m_pGetEncoderActive (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::GetController (int *plXC, int *plYC, int *plZC, int *plAC)
{
        if (m_pGetController)
        {
                return m_pGetController (m_LSID, plXC, plYC, plZC, plAC);
        }
        else
                return -1;
}

int CLStep64::GetControllerCall (int *plCtrCall)
{
        if (m_pGetControllerCall)
        {
                return m_pGetControllerCall (m_LSID, plCtrCall);
        }
        else
                return -1;
}

int CLStep64::GetControllerSteps (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetControllerSteps)
        {
                return m_pGetControllerSteps (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetControllerFactor (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetControllerFactor)
        {
                return m_pGetControllerFactor (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::GetControllerTWDelay (int *plCtrTWDelay)
{
        if (m_pGetControllerTWDelay)
        {
                return m_pGetControllerTWDelay (m_LSID, plCtrTWDelay);
        }
        else
                return -1;
}

int CLStep64::GetControllerTimeout (int *plACtrTimeout)
{
        if (m_pGetControllerTimeout)
        {
                return m_pGetControllerTimeout (m_LSID, plACtrTimeout);
        }
        else
                return -1;
}

int CLStep64::SetCtrFastMoveOn ()
{
        if (m_pSetCtrFastMoveOn)
        {
                return m_pSetCtrFastMoveOn (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetCtrFastMoveOff ()
{
        if (m_pSetCtrFastMoveOff)
        {
                return m_pSetCtrFastMoveOff (m_LSID);
        }
        else
                return -1;
}

int CLStep64::GetCtrFastMove (BOOL *pbActive)
{
        if (m_pGetCtrFastMove)
        {
                return m_pGetCtrFastMove (m_LSID, pbActive);
        }
        else
                return -1;
}

int CLStep64::ClearCtrFastMoveCounter ()
{
        if (m_pClearCtrFastMoveCounter)
        {
                return m_pClearCtrFastMoveCounter (m_LSID);
        }
        else
                return -1;
}

int CLStep64::GetCtrFastMoveCounter (int *plXC, int *plYC, int *plZC, int *plAC)
{
        if (m_pGetCtrFastMoveCounter)
        {
                return m_pGetCtrFastMoveCounter (m_LSID, plXC, plYC, plZC, plAC);
        }
        else
                return -1;
}

int CLStep64::ClearEncoder (int lAxis)
{
        if (m_pClearEncoder)
        {
                return m_pClearEncoder (m_LSID, lAxis);
        }
        else
                return -1;
}

int CLStep64::GetEncoder (double *pdXP, double *pdYP, double *pdZP, double *pdAP)
{
        if (m_pGetEncoder)
        {
                return m_pGetEncoder (m_LSID, pdXP, pdYP, pdZP, pdAP);
        }
        else
                return -1;
}

int CLStep64::GetTrigger (BOOL *pbATrigger)
{
        if (m_pGetTrigger)
        {
                return m_pGetTrigger (m_LSID, pbATrigger);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_ (int *plATrigger)
{
        if (m_pGetTrigger_)
        {
                return m_pGetTrigger_ (m_LSID, plATrigger);
        }
        else
                return -1;
}

int CLStep64::GetTriggerPar (int *plAxis, int *plMode, int *plSignal, double *pdDistance)
{
        if (m_pGetTriggerPar)
        {
                return m_pGetTriggerPar (m_LSID, plAxis, plMode, plSignal, pdDistance);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoPar (int *plAxis, int *plMode, int *plSignal, double *pdDistance)
{
        if (m_pGetTrigger_TwoPar)
        {
                return m_pGetTrigger_TwoPar (m_LSID, plAxis, plMode, plSignal, pdDistance);
        }
        else
                return -1;
}

int CLStep64::SetTriggerCount (Cardinal Value)
{
        if (m_pSetTriggerCount)
        {
                return m_pSetTriggerCount (m_LSID, Value);
        }
        else
                return -1;
}

int CLStep64::GetTriggerCount (Cardinal *pValue)
{
        if (m_pGetTriggerCount)
        {
                return m_pGetTriggerCount (m_LSID, pValue);
        }
        else
                return -1;
}

int CLStep64::SetTrigCount (int lValue)
{
        if (m_pSetTrigCount)
        {
                return m_pSetTrigCount (m_LSID, lValue);
        }
        else
                return -1;
}

int CLStep64::GetTrigCount (int *plValue)
{
        if (m_pGetTrigCount)
        {
                return m_pGetTrigCount (m_LSID, plValue);
        }
        else
                return -1;
}

int CLStep64::SetTrigger_TwoCount (Cardinal Value)
{
        if (m_pSetTrigger_TwoCount)
        {
                return m_pSetTrigger_TwoCount (m_LSID, Value);
        }
        else
                return -1;
}

int CLStep64::GetTrigger_TwoCount (Cardinal *pValue)
{
        if (m_pGetTrigger_TwoCount)
        {
                return m_pGetTrigger_TwoCount (m_LSID, pValue);
        }
        else
                return -1;
}

int CLStep64::SetSnapShotSource (int lX, int lY, int lZ, int lR)
{
        if (m_pSetSnapShotSource)
        {
                return m_pSetSnapShotSource (m_LSID, lX, lY, lZ, lR);
        }
        else
                return -1;
}

int CLStep64::GetSnapShotSource (int *plX, int *plY, int *plZ, int *plR)
{
        if (m_pGetSnapShotSource)
        {
                return m_pGetSnapShotSource (m_LSID, plX, plY, plZ, plR);
        }
        else
                return -1;
}

int CLStep64::SetTVRInPulse (int lAxis, BOOL bDirection)
{
        if (m_pSetTVRInPulse)
        {
                return m_pSetTVRInPulse (m_LSID, lAxis, bDirection);
        }
        else
                return -1;
}

int CLStep64::GetSnapshot (BOOL *pbASnapshot)
{
        if (m_pGetSnapshot)
        {
                return m_pGetSnapshot (m_LSID, pbASnapshot);
        }
        else
                return -1;
}

int CLStep64::SetSnapshotFilter (int lTime)
{
        if (m_pSetSnapshotFilter)
        {
                return m_pSetSnapshotFilter (m_LSID, lTime);
        }
        else
                return -1;
}

int CLStep64::GetSnapshotFilter (int *plTime)
{
        if (m_pGetSnapshotFilter)
        {
                return m_pGetSnapshotFilter (m_LSID, plTime);
        }
        else
                return -1;
}

int CLStep64::GetSnapshotPar (BOOL *pbHigh, BOOL *pbAutoMode)
{
        if (m_pGetSnapshotPar)
        {
                return m_pGetSnapshotPar (m_LSID, pbHigh, pbAutoMode);
        }
        else
                return -1;
}

int CLStep64::GetLimit (int lAxis, double *pdMinRange, double *pdMaxRange)
{
        if (m_pGetLimit)
        {
                return m_pGetLimit (m_LSID, lAxis, pdMinRange, pdMaxRange);
        }
        else
                return -1;
}

int CLStep64::JoyChangeAxis (BOOL bValue)
{
        if (m_pJoyChangeAxis)
        {
                return m_pJoyChangeAxis (m_LSID, bValue);
        }
        else
                return -1;
}

int CLStep64::GetJoyChangeAxis (BOOL *pbValue)
{
        if (m_pGetJoyChangeAxis)
        {
                return m_pGetJoyChangeAxis (m_LSID, pbValue);
        }
        else
                return -1;
}

int CLStep64::SetDigJoyOff ()
{
        if (m_pSetDigJoyOff)
        {
                return m_pSetDigJoyOff (m_LSID);
        }
        else
                return -1;
}

int CLStep64::SetInputTrigMove (int lMode, BOOL bWait)
{
        if (m_pSetInputTrigMove)
        {
                return m_pSetInputTrigMove (m_LSID, lMode, bWait);
        }
        else
                return -1;
}

int CLStep64::GetInputTrigMove (int *plMode)
{
        if (m_pGetInputTrigMove)
        {
                return m_pGetInputTrigMove (m_LSID, plMode);
        }
        else
                return -1;
}

int CLStep64::SetLimitControlMode (int lMode)
{
        if (m_pSetLimitControlMode)
        {
                return m_pSetLimitControlMode (m_LSID, lMode);
        }
        else
                return -1;
}

int CLStep64::GetLimitControlMode (int *plMode)
{
        if (m_pGetLimitControlMode)
        {
                return m_pGetLimitControlMode (m_LSID, plMode);
        }
        else
                return -1;
}

int CLStep64::Initialize (char *pcWorkpath)
{
        if (m_pInitialize)
        {
                return m_pInitialize (m_LSID, pcWorkpath);
        }
        else
                return -1;
}

int CLStep64::InitializeW (TCHAR *pcWorkpath)
{
        if (m_pInitializeW)
        {
                return m_pInitializeW (m_LSID, pcWorkpath);
        }
        else
                return -1;
}

int CLStep64::SetAccelJerk (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetAccelJerk)
        {
                return m_pSetAccelJerk (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::SetDecelJerk (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetDecelJerk)
        {
                return m_pSetDecelJerk (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::SetCalibRMJerk (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetCalibRMJerk)
        {
                return m_pSetCalibRMJerk (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::SetJoyVel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetJoyVel)
        {
                return m_pSetJoyVel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetJoyVel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetJoyVel)
        {
                return m_pGetJoyVel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetJoyOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetJoyOutPass)
        {
                return m_pSetJoyOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetJoyOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetJoyOutPass)
        {
                return m_pGetJoyOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetTippOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetTippOutPass)
        {
                return m_pSetTippOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetTippOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetTippOutPass)
        {
                return m_pGetTippOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetMotorBrakeDigOut (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetMotorBrakeDigOut)
        {
                return m_pSetMotorBrakeDigOut (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetMotorBrakeDigOut (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetMotorBrakeDigOut)
        {
                return m_pGetMotorBrakeDigOut (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::GetMotorBrakeOut (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetMotorBrakeOut)
        {
                return m_pGetMotorBrakeOut (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBall (BOOL bStatus)
{
        if (m_pSetTrackBall)
        {
                return m_pSetTrackBall (m_LSID, bStatus);
        }
        else
                return -1;
}

int CLStep64::GetTrackBall (BOOL *pbStatus)
{
        if (m_pGetTrackBall)
        {
                return m_pGetTrackBall (m_LSID, pbStatus);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallVel (double dX, double dY, double dZ, double dA)
{
        if (m_pSetTrackBallVel)
        {
                return m_pSetTrackBallVel (m_LSID, dX, dY, dZ, dA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallVel (double *pdX, double *pdY, double *pdZ, double *pdA)
{
        if (m_pGetTrackBallVel)
        {
                return m_pGetTrackBallVel (m_LSID, pdX, pdY, pdZ, pdA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallEnable (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetTrackBallEnable)
        {
                return m_pSetTrackBallEnable (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallEnable (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetTrackBallEnable)
        {
                return m_pGetTrackBallEnable (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallRedCur (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetTrackBallRedCur)
        {
                return m_pSetTrackBallRedCur (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallRedCur (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetTrackBallRedCur)
        {
                return m_pGetTrackBallRedCur (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallDir (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetTrackBallDir)
        {
                return m_pSetTrackBallDir (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallDir (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetTrackBallDir)
        {
                return m_pGetTrackBallDir (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallToAxis (int lX, int lY, int lZ, int lA)
{
        if (m_pSetTrackBallToAxis)
        {
                return m_pSetTrackBallToAxis (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallToAxis (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetTrackBallToAxis)
        {
                return m_pGetTrackBallToAxis (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetTrackBallOutPass (int lX, int lY, int lZ, int lA)
{
        if (m_pSetTrackBallOutPass)
        {
                return m_pSetTrackBallOutPass (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetTrackBallOutPass (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetTrackBallOutPass)
        {
                return m_pGetTrackBallOutPass (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetDigInStatus (int lstatus, char *pcFeedback, int lMaxLen)
{
        if (m_pSetDigInStatus)
        {
                return m_pSetDigInStatus (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetDigInStatusW (int lstatus, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pSetDigInStatusW)
        {
                return m_pSetDigInStatusW (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetDigInStatus (int *plstatus)
{
        if (m_pGetDigInStatus)
        {
                return m_pGetDigInStatus (m_LSID, plstatus);
        }
        else
                return -1;
}

int CLStep64::SetDigInExtStatus (int lstatus, char *pcFeedback, int lMaxLen)
{
        if (m_pSetDigInExtStatus)
        {
                return m_pSetDigInExtStatus (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetDigInExtStatusW (int lstatus, TCHAR *pcFeedback, int lMaxLen)
{
        if (m_pSetDigInExtStatusW)
        {
                return m_pSetDigInExtStatusW (m_LSID, lstatus, pcFeedback, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::GetDigInExtStatus (int *plstatus)
{
        if (m_pGetDigInExtStatus)
        {
                return m_pGetDigInExtStatus (m_LSID, plstatus);
        }
        else
                return -1;
}

int CLStep64::SetTTLDigOut (int lstatus)
{
        if (m_pSetTTLDigOut)
        {
                return m_pSetTTLDigOut (m_LSID, lstatus);
        }
        else
                return -1;
}

int CLStep64::GetTTLDigOut (int *plstatus)
{
        if (m_pGetTTLDigOut)
        {
                return m_pGetTTLDigOut (m_LSID, plstatus);
        }
        else
                return -1;
}

int CLStep64::GetTTLDigIn (int *plstatus)
{
        if (m_pGetTTLDigIn)
        {
                return m_pGetTTLDigIn (m_LSID, plstatus);
        }
        else
                return -1;
}

int CLStep64::SetTVR (BOOL bX, BOOL bY, BOOL bZ, BOOL bA)
{
        if (m_pSetTVR)
        {
                return m_pSetTVR (m_LSID, bX, bY, bZ, bA);
        }
        else
                return -1;
}

int CLStep64::GetTVR (BOOL *pbX, BOOL *pbY, BOOL *pbZ, BOOL *pbA)
{
        if (m_pGetTVR)
        {
                return m_pGetTVR (m_LSID, pbX, pbY, pbZ, pbA);
        }
        else
                return -1;
}

int CLStep64::SetTVRToAxis (int lX, int lY, int lZ, int lA)
{
        if (m_pSetTVRToAxis)
        {
                return m_pSetTVRToAxis (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetTVRToAxis (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetTVRToAxis)
        {
                return m_pGetTVRToAxis (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetDeceleration (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetDeceleration)
        {
                return m_pSetDeceleration (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetDeceleration (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetDeceleration)
        {
                return m_pGetDeceleration (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetDecelSingleAxis (int lAxis, double dValue)
{
        if (m_pSetDecelSingleAxis)
        {
                return m_pSetDecelSingleAxis (m_LSID, lAxis, dValue);
        }
        else
                return -1;
}

int CLStep64::ConfigMaxAxes (int lnAxes)
{
        if (m_pConfigMaxAxes)
        {
                return m_pConfigMaxAxes (m_LSID, lnAxes);
        }
        else
                return -1;
}

int CLStep64::SetMotorBrake (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMotorBrake)
        {
                return m_pSetMotorBrake (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMotorBrake (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMotorBrake)
        {
                return m_pGetMotorBrake (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetJoystickAxes (int lFlags)
{
        if (m_pSetJoystickAxes)
        {
                return m_pSetJoystickAxes (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::GetJoystickAxes (int *plFlags)
{
        if (m_pGetJoystickAxes)
        {
                return m_pGetJoystickAxes (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::SetJoyVelSkal (int lX, int lY, int lZ, int lA)
{
        if (m_pSetJoyVelSkal)
        {
                return m_pSetJoyVelSkal (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetJoyVelSkal (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetJoyVelSkal)
        {
                return m_pGetJoyVelSkal (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetMaxUserCurrent (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetMaxUserCurrent)
        {
                return m_pSetMaxUserCurrent (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetMaxUserCurrent (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetMaxUserCurrent)
        {
                return m_pGetMaxUserCurrent (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetStopDecel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetStopDecel)
        {
                return m_pSetStopDecel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetStopDecel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetStopDecel)
        {
                return m_pGetStopDecel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetMotorMaxVel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetMotorMaxVel)
        {
                return m_pSetMotorMaxVel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetMotorMaxVel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetMotorMaxVel)
        {
                return m_pGetMotorMaxVel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetMotorStandForce (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetMotorStandForce)
        {
                return m_pSetMotorStandForce (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetMotorStandForce (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetMotorStandForce)
        {
                return m_pGetMotorStandForce (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetMotorStandMoment (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetMotorStandMoment)
        {
                return m_pSetMotorStandMoment (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetMotorStandMoment (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetMotorStandMoment)
        {
                return m_pGetMotorStandMoment (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetMotorFieldDir (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMotorFieldDir)
        {
                return m_pSetMotorFieldDir (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMotorFieldDir (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMotorFieldDir)
        {
                return m_pGetMotorFieldDir (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetMotorType (int lX, int lY, int lZ, int lA)
{
        if (m_pSetMotorType)
        {
                return m_pSetMotorType (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetMotorType (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetMotorType)
        {
                return m_pGetMotorType (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetOsziCallBackFct (void* pFct)
{
        if (m_pSetOsziCallBackFct)
        {
                return m_pSetOsziCallBackFct (m_LSID, pFct);
        }
        else
                return -1;
}

int CLStep64::TranslateErrMsg (TCHAR *pcMsgIn, TCHAR *pcMsgOut, int lMaxLen)
{
        if (m_pTranslateErrMsg)
        {
                return m_pTranslateErrMsg (m_LSID, pcMsgIn, pcMsgOut, lMaxLen);
        }
        else
                return -1;
}

int CLStep64::SetCalibRMAccel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetCalibRMAccel)
        {
                return m_pSetCalibRMAccel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetCalibRMAccel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetCalibRMAccel)
        {
                return m_pGetCalibRMAccel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::GetCalibRMJerk (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetCalibRMJerk)
        {
                return m_pGetCalibRMJerk (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetCalibRMVel (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetCalibRMVel)
        {
                return m_pSetCalibRMVel (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetCalibRMVel (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetCalibRMVel)
        {
                return m_pGetCalibRMVel (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetCalibRMBackSpeed (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetCalibRMBackSpeed)
        {
                return m_pSetCalibRMBackSpeed (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetCalibRMBackSpeed (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetCalibRMBackSpeed)
        {
                return m_pGetCalibRMBackSpeed (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::GetAccelJerk (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetAccelJerk)
        {
                return m_pGetAccelJerk (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::GetDecelJerk (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetDecelJerk)
        {
                return m_pGetDecelJerk (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetGearDenominator (int lX, int lY, int lZ, int lA)
{
        if (m_pSetGearDenominator)
        {
                return m_pSetGearDenominator (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetGearDenominator (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetGearDenominator)
        {
                return m_pGetGearDenominator (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetGearNumerator (int lX, int lY, int lZ, int lA)
{
        if (m_pSetGearNumerator)
        {
                return m_pSetGearNumerator (m_LSID, lX, lY, lZ, lA);
        }
        else
                return -1;
}

int CLStep64::GetGearNumerator (int *plX, int *plY, int *plZ, int *plA)
{
        if (m_pGetGearNumerator)
        {
                return m_pGetGearNumerator (m_LSID, plX, plY, plZ, plA);
        }
        else
                return -1;
}

int CLStep64::SetStopDecelJerk (double dXD, double dYD, double dZD, double dAD)
{
        if (m_pSetStopDecelJerk)
        {
                return m_pSetStopDecelJerk (m_LSID, dXD, dYD, dZD, dAD);
        }
        else
                return -1;
}

int CLStep64::GetStopDecelJerk (double *pdXD, double *pdYD, double *pdZD, double *pdAD)
{
        if (m_pGetStopDecelJerk)
        {
                return m_pGetStopDecelJerk (m_LSID, pdXD, pdYD, pdZD, pdAD);
        }
        else
                return -1;
}

int CLStep64::SetSwChange (int lFlags)
{
        if (m_pSetSwChange)
        {
                return m_pSetSwChange (m_LSID, lFlags);
        }
        else
                return -1;
}

int CLStep64::GetSwChange (int *plFlags)
{
        if (m_pGetSwChange)
        {
                return m_pGetSwChange (m_LSID, plFlags);
        }
        else
                return -1;
}

int CLStep64::SetExtCallBackFct (void* pFct, void* ppprivate)
{
        if (m_pSetExtCallBackFct)
        {
                return m_pSetExtCallBackFct (m_LSID, pFct, ppprivate);
        }
        else
                return -1;
}
