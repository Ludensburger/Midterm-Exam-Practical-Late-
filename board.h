#include "entry.h"
class Scoreboard {
	entry board[5];
	int size;

	public:
	bool add(entry e) {
		bool added = false;
		for (int i = 0; i < size; i++) {
			entry exist = board[i];
			if (e.score > exist.score) {
				for (int j = size; j >= i+1; j--) {
					if (j == 5) {
						continue;
					}
					board[j] = board[j-1];
				}
				board[i] = e;
				if (size < 5) {
					size++;
				}
				added = true;
				return true;
			}
		}
			if (size < 5) {
				board[size++] = e;
                return true;
			} else {
				cout << "PUNO NA" << endl;
                return false;
			}
    }

    // This method added as reference.
    int banCollege(string college) {
        int ctr = 0;
        for (int i = 0; i < size; i++) {
        	entry e = board[i];
            if (college.compare(e.college) == 0) {
                for (int j = i; j < size-1; j++) {
                     board[j] = board[j+1];
                }
                ctr++;
                size--;
                i--;
            }
        }
        return ctr;
    }

    // TODO create and implement int forceFirst method here.

    int forceFirst(string college) {
        int removed = 0;

        // check thru looping if there's still contents in the list (size > 0)
        // and if the first college in the list matches the
        // selected college to be forced to first (board[0].college != college)

        while (size > 0 && board[0].college != college) {
            // if college doesnt match
            // remove the first entry and shift everything to the left

            for(int i = 0; i < size - 1; i++) {
                board[i] = board[i + 1];
            }

            // decrement size after removing and increment the counter
            size--;
            removed++;

        }

        return removed;

    }

    void print() {
        for (int i = 0; i < 5; i++) {
            if (i >= size) {
                cout << i+1 << ". (none)" << endl;
            } else {
            	entry e = board[i];
                cout << i+1 << ". " << e.name << " (" << e.college << ")" << " - " << e.score << endl;
            }
        }
        cout << endl;
    }
};
