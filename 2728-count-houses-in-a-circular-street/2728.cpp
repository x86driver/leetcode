/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        int count = 0;
        Street *ptr = street;
        for (int i = 0; i < k; ++i) {
            ptr->closeDoor();
            ptr->moveRight();
        }
        ptr->openDoor();
        while (k--) {
            ++count;
            ptr->moveRight();
            if (ptr->isDoorOpen()) {
                break;
            }
        }

        return count;
    }
};
