<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="store.aspx.cs" Inherits="companyproject.store" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <%-- <script src="Ja.js" type="text/javascript"></script>--%>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <main>
        <div id="tm-container-inner-2 tm-contact-section">
            <div class="row">
                <div class="searchbox">
                    <form action="" method="POST" class="tm-contact-form">
                        <div class="form-group">

                            <h3>BookTitle:</h3>
                            <asp:TextBox ID="TextBox3" class="form-control" runat="server"></asp:TextBox>

                        </div>


                        <div class="form-group tm-d-flex">

                            <asp:Button ID="Button5" runat="server" OnClick="search" class="tm-btn tm-btn-success tm-btn-right" Text="Search" />
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <div class="tm-paging-links">
            <nav>
                <ul>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button2" class="tm-paging-link active" CausesValidation="false" OnClick="onclickcat1" runat="server" Text="StoryBooks" /></li>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button3" class="tm-paging-link" CausesValidation="false" OnClick="onclickcat2" runat="server" Text="TextBooks" /></li>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button4" class="tm-paging-link" CausesValidation="false" OnClick="onclickcat3" runat="server" Text="TextBooks" /></li>

                </ul>
            </nav>

            <%--       <nav>
                    <ul>
                        <li class="tm-paging-item"><a href="#" class="tm-paging-link active">Pizza</a></li>
                        <li class="tm-paging-item"><a href="#" class="tm-paging-link">Salad</a></li>
                        <li class="tm-paging-item"><a href="#" class="tm-paging-link">Noodle</a></li>
                    </ul>
                </nav>--%>
        </div>
        <!-- Gallery -->
        <div class="row tm-gallery">
            <!-- gallery page 1 -->
            <asp:DataList ID="tmgallerypagepizza" class="tm-gallery-page" runat="server" DataKeyField="BookID" DataSourceID="SQLConnectioncommand1" RepeatDirection="Horizontal" RepeatColumns="5">
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
                                                Price: <%# Eval("Price") %>Rs<br />
                                                BookID: <%# Eval("BookID") %><br />
                                                Discount: <%# Eval("Discount") %>%
                                                <asp:Button ID="Button4" class="tm-paging-link" CommandName="Item" CommandArgument='<%# Eval("BookID") %>' OnCommand="Ratingfunc" runat="server" Text="User Reviews" />
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



        <div class="tm-container-inner-2 tm-contact-section">
            <div class="row">
                <div class="col-md-6">
                    <div class="form-group">

                        <h3>BookID:</h3>
                        <asp:TextBox ID="TextBox10" class="form-control" runat="server"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox10"
                            ForeColor="Red" Display="Dynamic" ErrorMessage="*Required" />
                    </div>

                    <div class="form-group">
                        <h3>Quantity:</h3>
                        <asp:TextBox ID="TextBox20" class="form-control" runat="server"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox20"
                            ForeColor="Red" Display="Dynamic" ErrorMessage="*Required" />
                    </div>

                    <div class="form-group tm-d-flex">

                        <asp:Button ID="Button1" runat="server" OnClick="addtoCart_Click" class="tm-btn tm-btn-success tm-btn-right" CausesValidation="true" Text="AddToCart" />
                    </div>


                </div>
            </div>
        </div>

        <br />

    </main>

    <asp:SqlDataSource ID="SQLConnectioncommand1" runat="server" ConnectionString="Data Source=DESKTOP-1CH50Q7; Initial Catalog=hookOnBookss; Integrated security= true"
        SelectCommand="Select * from Books where CategoryID=1"></asp:SqlDataSource>
    <%--	<script src="js/jquery.min.js"></script>
	<script src="js/parallax.min.js"></script>
	<script>
        $(document).ready(function () {
            // Handle click on paging links
            $('.tm-paging-link').click(function (e) {
                e.preventDefault();

                var page = $(this).text().toLowerCase();
                $('.tm-gallery-page').addClass('hidden');
                $('#tm-gallery-page-' + page).removeClass('hidden');
                $('.tm-paging-link').removeClass('active');
                $(this).addClass("active");
            });
        });
	</script>--%>
    <%--    <script>
        function but() {
           document.getElementById('<%=SQLConnectioncommand1 %>').SelectCommand = "Select * from Books where CategoryID=2";
            alert("js");
        }
    </script>--%>
</asp:Content>
