/*
SceneManager >> SceneManager

@Class SceneManager
->scene�� �����ϴ� Ŭ����.

@�ۼ���: ������
@�ۼ���: 14-8-21
@���� ������: 
@���� ������:
@���� ��������:
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
