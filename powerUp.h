
class powerUp
{
private:
	int powerUpX, powerUpY;
	int powerUpType = 0;

public:
	int getPowerUpX();
	int getPowerUpY();
	void powerUpUpdatePosition(int x, int y);
	void spawnPowerUp();
	void movePowerUp();
	void deletePowerUp();
	int getPowerUpType();
	void powerUpTypeRandomize();
};

