
struct cmdData
{
	unsigned short token;
	char *name;
	int args;
	char *(*fn) KITTENS_CMD_ARGS;
};


extern char *turboplusMultiYes KITTENS_CMD_ARGS;
extern char *turboplusMultiNo KITTENS_CMD_ARGS;
extern char *turboplusLsl_b KITTENS_CMD_ARGS;
extern char *turboplusLsl_w KITTENS_CMD_ARGS;
extern char *turboplusLsl_l KITTENS_CMD_ARGS;
extern char *turboplusLsr_b KITTENS_CMD_ARGS;
extern char *turboplusLsr_w KITTENS_CMD_ARGS;
extern char *turboplusLsr_l KITTENS_CMD_ARGS;
extern char *turboplusLSwap KITTENS_CMD_ARGS;
extern char *turboplusTest_b KITTENS_CMD_ARGS;
extern char *turboplusTest_w KITTENS_CMD_ARGS;
extern char *turboplusTest_l KITTENS_CMD_ARGS;
extern char *turboplusVblWait KITTENS_CMD_ARGS;
extern char *turboplusReserveCheck KITTENS_CMD_ARGS;
extern char *turboplusCheckErase KITTENS_CMD_ARGS;
extern char *turboplusCheck KITTENS_CMD_ARGS;
extern char *turboplusSetCheck KITTENS_CMD_ARGS;
extern char *turboplusResetCheck KITTENS_CMD_ARGS;
extern char *turboplusHitSprZone KITTENS_CMD_ARGS;
extern char *turboplusHitBobZone KITTENS_CMD_ARGS;
extern char *turboplusHitSprCheck KITTENS_CMD_ARGS;
extern char *turboplusRawKey KITTENS_CMD_ARGS;
extern char *turboplusRMove KITTENS_CMD_ARGS;
extern char *turboplusRDraw KITTENS_CMD_ARGS;
extern char *turboplusRBox KITTENS_CMD_ARGS;
extern char *turboplusRHome KITTENS_CMD_ARGS;
extern char *turboplusRBar KITTENS_CMD_ARGS;
extern char *turboplusReserveObject KITTENS_CMD_ARGS;
extern char *turboplusDefineDraw KITTENS_CMD_ARGS;
extern char *turboplusDefineMove KITTENS_CMD_ARGS;
extern char *turboplusDefineStop KITTENS_CMD_ARGS;
extern char *turboplusDefineAttr KITTENS_CMD_ARGS;
extern char *turboplusObjectDraw KITTENS_CMD_ARGS;
extern char *turboplusRObjectDraw KITTENS_CMD_ARGS;
extern char *turboplusObjectMagDraw KITTENS_CMD_ARGS;
extern char *turboplusRObjectMagDraw KITTENS_CMD_ARGS;
extern char *turboplusObjectErase KITTENS_CMD_ARGS;
extern char *turboplusLine3d KITTENS_CMD_ARGS;
extern char *turboplusEye3d KITTENS_CMD_ARGS;
extern char *turboplusObjectSave KITTENS_CMD_ARGS;
extern char *turboplusObjectLoad KITTENS_CMD_ARGS;
extern char *turboplusBlitStoreLeft KITTENS_CMD_ARGS;
extern char *turboplusMultiBlit KITTENS_CMD_ARGS;
extern char *turboplusBlitErase KITTENS_CMD_ARGS;
extern char *turboplusBlitSpeed KITTENS_CMD_ARGS;
extern char *turboplusBlitLeft KITTENS_CMD_ARGS;
extern char *turboplusFPlot KITTENS_CMD_ARGS;
extern char *turboplusBlitClear KITTENS_CMD_ARGS;
extern char *turboplusLeftClick KITTENS_CMD_ARGS;
extern char *turboplusReserveStars KITTENS_CMD_ARGS;
extern char *turboplusDefineStar KITTENS_CMD_ARGS;
extern char *turboplusDisplayStars KITTENS_CMD_ARGS;
extern char *turboplusStarsErase KITTENS_CMD_ARGS;
extern char *turboplusStarsCompute KITTENS_CMD_ARGS;
extern char *turboplusStarsDraw KITTENS_CMD_ARGS;
extern char *turboplusStarsSpeed KITTENS_CMD_ARGS;
extern char *turboplusStarsClip KITTENS_CMD_ARGS;
extern char *turboplusFPoint KITTENS_CMD_ARGS;
extern char *turboplusFCircle KITTENS_CMD_ARGS;
extern char *turboplusFSqr KITTENS_CMD_ARGS;
extern char *turboplusStarsIntOn KITTENS_CMD_ARGS;
extern char *turboplusStarsIntOff KITTENS_CMD_ARGS;
extern char *turboplusBlitIntOn KITTENS_CMD_ARGS;
extern char *turboplusBlitIntOff KITTENS_CMD_ARGS;
extern char *turboplusFDraw KITTENS_CMD_ARGS;
extern char *turboplusObjectLimit KITTENS_CMD_ARGS;
extern char *turboplusSetPlanes KITTENS_CMD_ARGS;
extern char *turboplusPlaneOffset KITTENS_CMD_ARGS;
extern char *turboplusPlaneSwap KITTENS_CMD_ARGS;
extern char *turboplusPlaneShiftUp KITTENS_CMD_ARGS;
extern char *turboplusPlaneShiftDown KITTENS_CMD_ARGS;
extern char *turboplusPlaneUpdate KITTENS_CMD_ARGS;
extern char *turboplusFPasteIcon KITTENS_CMD_ARGS;
extern char *turboplusF32Icon KITTENS_CMD_ARGS;
extern char *turboplusF16Icon KITTENS_CMD_ARGS;
extern char *turboplusF16procIcon KITTENS_CMD_ARGS;
extern char *turboplusF32procIcon KITTENS_CMD_ARGS;
extern char *turboplusXIcon KITTENS_CMD_ARGS;
extern char *turboplusYIcon KITTENS_CMD_ARGS;
extern char *turboplusPlanesIcon KITTENS_CMD_ARGS;
extern char *turboplusCpuInfo KITTENS_CMD_ARGS;
extern char *turboplusMathInfo KITTENS_CMD_ARGS;
extern char *turboplusFPutBlock KITTENS_CMD_ARGS;
extern char *turboplusReserveStaticBlock KITTENS_CMD_ARGS;
extern char *turboplusStaticBlockErase KITTENS_CMD_ARGS;
extern char *turboplusBuildStaticBlock KITTENS_CMD_ARGS;
extern char *turboplusFPutStaticBlock KITTENS_CMD_ARGS;
extern char *turboplusSceneBank KITTENS_CMD_ARGS;
extern char *turboplusSceneCheck KITTENS_CMD_ARGS;
extern char *turboplusScene16Check KITTENS_CMD_ARGS;
extern char *turboplusSceneChange KITTENS_CMD_ARGS;
extern char *turboplusScene16Change KITTENS_CMD_ARGS;
extern char *turboplusScene16Draw KITTENS_CMD_ARGS;
extern char *turboplusScene16Def KITTENS_CMD_ARGS;
extern char *turboplusScene16Restore KITTENS_CMD_ARGS;
extern char *turboplusScene16Limit KITTENS_CMD_ARGS;
extern char *turboplusScene32Check KITTENS_CMD_ARGS;
extern char *turboplusScene32Change KITTENS_CMD_ARGS;
extern char *turboplusScene32Draw KITTENS_CMD_ARGS;
extern char *turboplusScene16View KITTENS_CMD_ARGS;
extern char *turboplusScene32View KITTENS_CMD_ARGS;
extern char *turboplusScene16Do KITTENS_CMD_ARGS;
extern char *turboplusScene32Do KITTENS_CMD_ARGS;
extern char *turboplusScene16Top KITTENS_CMD_ARGS;
extern char *turboplusScene32Top KITTENS_CMD_ARGS;
extern char *turboplusScene16Bottom KITTENS_CMD_ARGS;
extern char *turboplusScene32Bottom KITTENS_CMD_ARGS;
extern char *turboplusScene16Left KITTENS_CMD_ARGS;
extern char *turboplusScene32Left KITTENS_CMD_ARGS;
extern char *turboplusScene16Right KITTENS_CMD_ARGS;
extern char *turboplusScene32Right KITTENS_CMD_ARGS;
extern char *turboplusSceneX KITTENS_CMD_ARGS;
extern char *turboplusSceneY KITTENS_CMD_ARGS;
extern char *turboplusAmosPri KITTENS_CMD_ARGS;
extern char *turboplusBitFieldIns KITTENS_CMD_ARGS;
extern char *turboplusBitFieldExt KITTENS_CMD_ARGS;
extern char *turboplusHitBobCheck KITTENS_CMD_ARGS;
extern char *turboplusByteHunt KITTENS_CMD_ARGS;
extern char *turboplusWorkbenchOpen KITTENS_CMD_ARGS;
extern char *turboplusSceneLoad KITTENS_CMD_ARGS;
extern char *turboplusMemoryFill KITTENS_CMD_ARGS;
extern char *turboplusBlitIntChange KITTENS_CMD_ARGS;
extern char *turboplusBlitIntWait KITTENS_CMD_ARGS;
extern char *turboplusRange KITTENS_CMD_ARGS;
extern char *turboplusTexp KITTENS_CMD_ARGS;
extern char *turboplusBlitUp KITTENS_CMD_ARGS;
extern char *turboplusBlitStoreUp KITTENS_CMD_ARGS;
extern char *turboplusIconCheck KITTENS_CMD_ARGS;
extern char *turboplusSceneIconBank KITTENS_CMD_ARGS;
extern char *turboplusTClip KITTENS_CMD_ARGS;
extern char *turboplusBetween KITTENS_CMD_ARGS;
extern char *turboplusScenePalette KITTENS_CMD_ARGS;
extern char *turboplusSceneMaskPalette KITTENS_CMD_ARGS;
extern char *turboplusBankEnd KITTENS_CMD_ARGS;
extern char *turboplusDebug KITTENS_CMD_ARGS;










