#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int degree_of_min = 0;

	cin >> n >> k;
	vector<int> multi_tab(n);
	vector<int> electronic_products(k);

	for (int i = 0; i < k; i++) {
		cin >> electronic_products[i];
	}

    for (int i = 0; i < k; i++)
    {
        bool need_to_unplug = true;

        for (int j = 0; j < n; j++) {
            if (multi_tab[j] == electronic_products[i] || !multi_tab[j])
            {
                multi_tab[j] = electronic_products[i];
                need_to_unplug = false;
                break;
            }
        }

        if (!need_to_unplug) {
            continue;
        }
        else {
            int selected_plug, most_time_left = -1;
            for (int j = 0; j < n; j++)
            {
                int time_to_reuse = 0;
                for (int a = i + 1; a < k; a++)
                {
                    if (multi_tab[j] == electronic_products[a])
                        break;
                    time_to_reuse++;
                }

                if (time_to_reuse > most_time_left)
                {
                    selected_plug = j;
                    most_time_left = time_to_reuse;
                }
            }
            degree_of_min++;
            multi_tab[selected_plug] = electronic_products[i];
        }
    }

    cout << degree_of_min << "\n";


	return 0;
}