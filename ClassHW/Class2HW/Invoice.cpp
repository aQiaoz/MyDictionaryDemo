#include <iostream>
#include <string.h>
using namespace std;
#include "Invoice.h"

Invoice::Invoice(string number,string description,int quantity,int price)
{
    setPartNumber(number);
    setPartDescription(description);
    setQuantity(quantity);
    setPricePerItem(price);
}
void Invoice::setPartNumber(string number)
{
    inumber=number;
}
string Invoice::getPartNumber()
{
    return inumber;
}
void Invoice::setPartDescription(string descripton)
{
    idescription=descripton;
}
string Invoice::getPartDescription()
{
    return idescription;
}
void Invoice::setQuantity(int quantity)
{
    if(quantity<=0)
    {
        quantity=0;
    }
    iquantity=quantity;
}
int Invoice::getQuantity()
{
    return iquantity;
}
void Invoice::setPricePerItem(int price)
{
    if(price<=0)
    {
        price=0;
    }
    iprice=price;
}
int Invoice::getPricePerItem()
{
    return iprice;
}
int Invoice::getInvoiceAmount()
{
    iamount=iprice*iquantity;
    return iamount;
}

int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );

    // display the invoice data members and calculate the amount    
        cout << "Part number: " << 
    invoice.getPartNumber() << endl;    
        cout << "Part description: " << 
    invoice.getPartDescription() << endl;    
        cout << "Quantity: " << 
    invoice.getQuantity() << endl;    
        cout << "Price per item: $" << 
    invoice.getPricePerItem() << endl;    
        cout << "Invoice amount: $" << 
    invoice.getInvoiceAmount() << endl;


//quantity cannot be negative. quantity set to 0
    // modify the invoice data members    
    invoice.setPartNumber( "123456" );    
    invoice.setPartDescription( "Saw" );    
    invoice.setQuantity( -5 );
    cout<<endl;
    if(invoice.getQuantity()==0)
    {
        cout<<"quantity cannot be negative. quantity set to 0"<< endl;
    }
    if(invoice.getPricePerItem()==0)
    {
        cout<<"PricePerItem cannot be negative.  PricePerItem set to 0"<< endl;
    }

    // negative quantity, so quantity set to 0    
    invoice.setPricePerItem( 10 );    
        cout << "\nInvoice data members modified.\n";    
        // display the modified invoice data members and calculate new amount    
        cout << "Part number: " << 
    invoice.getPartNumber() << endl;    
        cout << "Part description: " << 
    invoice.getPartDescription() << endl;    
        cout << "Quantity: " << 
    invoice.getQuantity() << endl;
        cout << "Price per item: $" << 
    invoice.getPricePerItem() << endl;    
        cout << "Invoice amount: $" << 
    invoice.getInvoiceAmount() << endl;    
    return 0; 
    // indicate successful termination} 
    // end main
}