using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace companyproject
{
    public class Cart
    {
        public List<CartItem> Items { get; set; }

        public Cart()
        {
            Items = new List<CartItem>();
        }

        private int ItemIndexOf(int Id)
        {
            foreach (CartItem item in Items)
            {
                if(item.ID==Id)
                {
                    return Items.IndexOf(item);
                }
            }
            return -1;
        }

        public void insert(CartItem item)
        {
            int index = ItemIndexOf(item.ID);
            if(index==-1)
            {
                Items.Add(item);
            }
            else
            {
                Items[index].quantity = Items[index].quantity + item.quantity;
            }
        }
        public void delete(int rowID)
        {
            Items.RemoveAt(rowID);
        }
        public void update(int rowID, int quantity)
        {
            if(quantity>0)
            {
                Items[rowID].quantity = quantity;
            }
            else
            {
                delete(rowID);
            }
        }

        public double GrandTotal
        {
            get
            {
                if(Items==null)
                {
                    return 0;
                }
                else
                {
                    double total = 0;
                    foreach (CartItem item in Items)
                    {
                        total += item.quantity * item.price;
                    }
                    return total;
                }
            }
        }
    }
}