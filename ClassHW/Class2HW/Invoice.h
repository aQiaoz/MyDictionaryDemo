#include <string.h>
using namespace std;
class Invoice
{
    public:
        Invoice(string number,string description,int quantity,int price);
        void setPartNumber(string nmuber);
        string getPartNumber();
        void setPartDescription(string);
        string getPartDescription();
        void setQuantity(int quantity);
        int getQuantity();
        void setPricePerItem(int price);
        int getPricePerItem();
        int getInvoiceAmount();

    private:
        string inumber,idescription;
        int iquantity,iprice,iamount;
};