/*
SceneManager >> SceneManager

@Class SceneManager
->scene을 관리하는 클래스.

@작성자: 남현욱
@작성일: 14-8-21
@최종 수정자: 
@최종 수정일:
@최종 수정사유:
*/


class AESceneManager
{
public:
	virtual void Render();
	virtual void Update();
	virtual bool ChangeScene();
	virtual bool DeleteScene();
	virtual bool AddScene();
protected:
	AESceneManager();
	virtual ~AESceneManager();

};
