class Position {
public:

    Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    void SetPosition(float xPos, float yPos){
        x = xPos;
        y = yPos;
    }
    float GetX() {
        return x;
    }
    float GetY() {
        return y;
    }

private:
    float x;
    float y;
};