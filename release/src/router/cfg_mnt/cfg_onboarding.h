#ifndef __CFG_ONBOARDING_H__
#define __CFG_ONBOARDING_H__

#define ONBOARDING_FILE_LOCK	"onboarding"
#define ONBOARDING_LIST_JSON_PATH	"/tmp/onboarding.json"
#define ONBOARDING_STATUS_PATH	"/tmp/obstatus"
#define WPS_CHECK_TIME		5
#define WPS_TIMEOUT		180		// 3 minutes
#define ONBOARDING_CHECK_TIME		30
#define ONBOARDING_TIMEOUT	240
#define ONBOARDING_AVAILABLE_TIMEOUT		180

enum onboardingType {
	OB_TYPE_OFF = 1,
	OB_TYPE_AVAILABLE,
	OB_TYPE_REQ,
	OB_TYPE_LOCKED
};

enum onboardingStatus {
	OB_STATUS_REQ = 0,
	OB_STATUS_START,
	OB_STATUS_SUCCESS,
	OB_STATUS_WPS_SUCCESS,
	OB_STATUS_WPS_FAIL,
	OB_STATUS_TERMINATE
};

enum vsieType {
	VSIE_TYPE_STATUS = 1,
	VSIE_TYPE_COST,
	VSIE_TYPE_ID,
	VSIE_TYPE_RE_MAC,
	VSIE_TYPE_MODEL_NAME
};

extern int cm_isOnboardingAvailable();
extern void cm_processOnboardingEvent(char *inData);
extern void cm_processOnboardingList(char *msg);
extern void cm_stopWps();
extern void cm_stopOnboardingMonitor();
extern void cm_updateOnboardingListStatus(char *reMac, char *newReMac, int obStatus);
extern void cm_updateOnboardingSuccess(unsigned char *msg);
extern int cm_checkOnboardingNewReValid(unsigned char *msg);
extern void cm_initOnboardingStatus();
extern void cm_updateOnboardingStatus(int obStatus);
extern int cm_obtainOnboardingStatusFromFile();

#endif /* __CFG_ONBOARDING_H__ */
/* End of cfg_onboarding.h */
