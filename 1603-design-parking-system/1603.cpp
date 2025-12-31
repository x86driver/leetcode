class ParkingSystem {
private:
    vector<int> park;
public:
    ParkingSystem(int big, int medium, int small) {
        park = {0, big, medium, small};
    }

    bool addCar(int carType) {
        if (park[carType] <= 0) {
            return false;
        }
        --park[carType];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
