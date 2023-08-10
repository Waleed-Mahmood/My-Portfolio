<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="Ratings.aspx.cs" Inherits="companyproject.Ratings" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div class="row tm-gallery">
        <!-- gallery page 1 -->
        <asp:DataList ID="tmgallerypagepizza" class="tm-gallery-page" runat="server" DataKeyField="BookID" DataSourceID="SQLConnectioncommand" RepeatDirection="Horizontal" RepeatColumns="5">
            <ItemTemplate>
                <table>
                    <tr>
                        <td class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">

                            <figcaption>
                                <div class="container">
                                    <asp:Image CssClass="image" ImageUrl='<%# Eval("Pictures") %>' runat="server" alt="Image" class="img-fluid tm-gallery-img" />
                                    <div class="overlay">
                                        <div class="text">
                                            Title: <%# Eval("Title") %>
                                            <br />
                                            Price: <%# Eval("Price") %>$<br />
                                            BookID: <%# Eval("BookID") %><br />
                                            Discount: <%# Eval("Discount") %>%<br />

                                        </div>
                                    </div>
                                </div>
                            </figcaption>
                        </td>

                    </tr>
                </table>
            </ItemTemplate>
        </asp:DataList>

    </div>

    <asp:DataList ID="DataList1" runat="server" DataKeyField="BookID" DataSourceID="Reviews123" RepeatDirection="Vertical" RepeatColumns="1">

     

        <ItemTemplate>


            <table class="customers">
            <th>Name</th>
            <th>Rating</th>
            <th>Comment</th>
                <tr>
                    <td><%# Eval("Gmail") %>
                    </td>
                    <td><%# Eval("Rating") %>
                    </td>
                    <td><%# Eval("Comment") %>
                    </td>

                </tr>
            </table>
        </ItemTemplate>
    </asp:DataList>
    <asp:SqlDataSource ID="SQLConnectioncommand" runat="server" ConnectionString="Data Source=DESKTOP-1CH50Q7; Initial Catalog=hookOnBookss; Integrated security= true"
        SelectCommand=""></asp:SqlDataSource>
    <asp:SqlDataSource ID="Reviews123" runat="server" ConnectionString="Data Source=DESKTOP-1CH50Q7; Initial Catalog=hookOnBookss; Integrated security= true"
        SelectCommand=""></asp:SqlDataSource>

</asp:Content>
