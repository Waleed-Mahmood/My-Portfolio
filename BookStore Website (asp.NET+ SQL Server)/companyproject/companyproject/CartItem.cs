using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace companyproject
{

    public class CartItem
    {
        public int ID { get; set; }
        public string title { get; set; }
        public int quantity { get; set; }
        public double price { get; set; }

        public CartItem()
        {

        }
        
        public CartItem(int id, string title, int quantity, double price)
        {
            this.ID = id;
            this.title = title;
            this.quantity = quantity;
            this.price = price;
        }

    }
}