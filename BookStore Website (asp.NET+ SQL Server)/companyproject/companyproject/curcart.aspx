<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="curcart.aspx.cs" Inherits="companyproject.curcart" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <div>
        </div>
        <br /> <br />  <br /> <br /> 
         <h1 id="bolde">Shopping Cart: </h1> <br /> <br /> 

        <asp:GridView ID="HookOnBooksCart" runat="server"  AutoGenerateColumns="False" Height="300px" style="margin-left: 295px" Width="802px" OnRowCancelingEdit="HookOnBooksCart_RowCancelingEdit" OnRowDeleting="HookOnBooksCart_RowDeleting" OnRowEditing="HookOnBooksCart_RowEditing" OnRowUpdating="HookOnBooksCart_RowUpdating">           
            
            <Columns>
                <asp:BoundField DataField="ID" HeaderText="BookID" ReadOnly="True" />
                <asp:BoundField DataField="TITLE" HeaderText="Title" ReadOnly="True" />
                <asp:BoundField DataField="PRICE" HeaderText="Price" ReadOnly="True" />
                <asp:BoundField DataField="QUANTITY" HeaderText="Quantity" />
                <asp:TemplateField HeaderText="Total">
                    <ItemTemplate>
                        <asp:Label ID="Label1" runat="server" Text='<%# Double.Parse(Eval("PRICE").ToString())*Int32.Parse(Eval("Quantity").ToString()) %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:CommandField ShowEditButton="True" />
                <asp:CommandField ShowDeleteButton="True" />
            </Columns>

         
           
        </asp:GridView>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
    <br /> &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="GrandTotal" runat="server" Visible="False"></asp:Label>
    <br />   <br />   <br />   <br />   <br />     <br />  <br />   <br />   <br /> 

  
</asp:Content>
