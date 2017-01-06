#define MAX_HEIGHT 20
#define MAX_LENGTH 120

class pipe
{
private:
	char pipeChar = 222;
	int pipex, pipey;
	int pipexInitialPosition, pipeyInitialPosition;
	int randomNumber = (rand() % 11) + 2;


public:

	pipe(int x)
	{
		pipex = x;
		pipey = 0;
		pipexInitialPosition = pipex;
		pipeyInitialPosition = pipey;
	}

	void movePipeLeftByOne();
	void deletePipe();
	void pipeReset(int x);
	int getGapInThePipe();
	int getPipeX() { return pipex; }

};

