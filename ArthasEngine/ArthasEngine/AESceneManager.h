
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
