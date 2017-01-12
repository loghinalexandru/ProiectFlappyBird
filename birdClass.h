class stupidBird
{
private:
	int birdx, birdy;
	int birdxCurrentPosition, birdyCurrentPosition;
	char playerBird = '>';


public:
	stupidBird(int x, int y)
	{
		birdx = x;
		birdy = y;
		birdxCurrentPosition = birdx;
		birdyCurrentPosition = birdy;
	}
	void birdReset();
	void moveBirdUp();
	void moveBirdDown(unsigned int dropDown);
	void eraseBird(int x, int y);
	void writeBird(int x, int y);
	int getBirdX();
	int getBirdY();
};


