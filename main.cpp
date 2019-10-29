#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    char ulang = 'y';

    vector<vector<string>> items{ { "Blade","22" },{ "Bow", "15" },{ "Staff","25" } ,{ "Shooter","32" },{ "katana","18" } };
	vector<vector<string>> inventory;
	vector<vector<string>>::iterator iter1;
	vector<string>::iterator iter2;

	unsigned int maksInventory = 3;
	long int maksItem = items.size();
	unsigned int pilihan = 0;
	unsigned int itemTerpilih = 0;
	unsigned int jumlahInventory = 0;
	unsigned int hapus = 0;

    while (ulang == 'y')
    {


    cout << "------------MENU---------" <<endl;
    cout << "[1] lihat inventory" <<endl;
    cout << "[2] dapatkan item acak" <<endl;
    cout << "[3] hapus item " << endl;
    cout << "Maksimal inventory adalah 3" << endl;
    cout << "Masukan pilihan anda :" ;
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        {
            if (inventory.empty())
            {
                cout << "inventory kosong " <<endl;
            }
            else
            {
                cout << "\nIsi inventory : " << endl;
				for (iter1 = inventory.begin(); iter1 != inventory.end(); ++iter1)
                {
					for (iter2 = iter1->begin(); iter2 != iter1->end(); iter2++)
					{
						cout << *iter2 << " ";
					}
					cout << endl;
				}
            }
            break;
        }

        case 2:
        {
			if (jumlahInventory >= maksInventory)
                {
				cout << "Inventory penuh ! " << endl;
                }
			else
			{
				srand((unsigned)time(0));
				itemTerpilih = (rand() % maksItem);


				cout << "Anda mendapat : " << items[itemTerpilih][0] << " . Stat : " << items[itemTerpilih][1] << endl;

				inventory.push_back(vector<string>({ items[itemTerpilih][0] }));
				inventory[jumlahInventory].push_back(items[itemTerpilih][1]);
				jumlahInventory++;
				cout << "Jumlah item sekarang : " << jumlahInventory << endl;
			}
			break;
        }

        case 3:
            {
                if (jumlahInventory <= 0)
            {
				cout << "Inventory kosong" << endl;
			}
			else {
				cout << "Hapus item ke - : ";
				cin >> hapus;

				if (hapus > jumlahInventory)
				{
					cout << "Item yang akan hapus tidak ada." << endl;
				}
				else
				{
					inventory.erase(inventory.begin() + (hapus - 1));
					jumlahInventory--;
					cout << "Jumlah inventory sekarang : " << jumlahInventory << endl;
				}
                }

			break;

            }

    }

        cout << "\nKembali ke Menu [y/n] ? ";
		cin >> ulang;
		cout << endl;

    }

    cout << "Back to game..." << endl;
	char ch; cin >> ch;
    return 0;
}
