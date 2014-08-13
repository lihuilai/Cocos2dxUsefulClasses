#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "cocos2d.h"
USING_NS_CC;

typedef void (CCObject::*SEL_JoystickEvent)(float interval,float x, float y);
#define joystickEvent_selector(_SELECTOR) (SEL_JoystickEvent)(&_SELECTOR)

/**
 *  ���ݸ�,�����Ͱ�ť�����Ǿ�����,���ǵ�ê��һֱ����ccp(0.5,0.5)
 *  ������setHandleEventListener��������ҡ��ҡ���¼��Ĵ���
 */
class Joystick : public CCNode,public CCTargetedTouchDelegate
{
public:
	Joystick(){}
	virtual ~Joystick(){}

	/**
	 * ����һ��ҡ��ʵ���ľ�̬����
	 *@param fnBg ����ͼƬ���ļ���,��������ҡ�˵ĵ��̾���
	 *@param bgRadius ҡ�˵ĵ��̵İ뾶
	 *@param fnHandle ҡ��ͼƬ���ļ���,��������ҡ�˾���
	 *@param handleRadius ҡ�˵İ뾶
	 */
	static Joystick* create(const char *fnBg,     float bgRadius,
					        const char *fnHandle, float handleRadius);

	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	void onEnter();
	void onExit();

	///����ҡ���ƶ�ʱҪ���õķ������������������Ϊvoid f��float interval, float x, float y��,interval��ʱ�����������x��y�ķ�Χ����0-1.0F
	void setHandleEventListener(CCObject *target, SEL_JoystickEvent selector);

	///�������ÿһ֡��������,���������ҡ���¼��Ĵ����Ļ���������ĸ���������
	void callHandleEvent(float interval);
protected:
	CCSprite* m_bg;        ///<���̵ľ���
	CCSprite* m_handle;    ///<ҡ�˵ľ���

	float m_bgRadius;      ///<���̵İ뾶
	float m_handleRadius;  ///<ҡ�˵İ뾶

	CCPoint m_handlePos;   ///<ҡ���ڵ�������ϵ������

	CCObject*         m_touchEventListener;
    SEL_JoystickEvent m_touchEventSelector;

	bool init(const char *fnBg,     float bgRadius,
			  const char *fnHandle, float handleRadius);
	
};

inline void Joystick::setHandleEventListener(CCObject *target, SEL_JoystickEvent selector)
{
	m_touchEventListener = target;
	m_touchEventSelector = selector;
}

#endif