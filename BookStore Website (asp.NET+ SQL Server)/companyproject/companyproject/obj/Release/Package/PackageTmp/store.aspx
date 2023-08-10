<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="store.aspx.cs" Inherits="companyproject.store" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <main>
        <div Id="tm-container-inner-2 tm-contact-section">
            <div class="row">
                <div class="searchbox">
                    <form action="" method="POST" class="tm-contact-form">
                        <div class="form-group">

                            <h3>BookName:</h3>
                            <asp:TextBox ID="TextBox3" class="form-control" runat="server"></asp:TextBox>

                        </div>


                        <div class="form-group tm-d-flex">

                            <asp:Button ID="Button5" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Search" />
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <div class="tm-paging-links">
            <nav>
                <ul>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button2" class="tm-paging-link active" runat="server" Text="StoryBooks" /></li>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button3" class="tm-paging-link" runat="server" Text="TextBooks" /></li>
                    <li class="tm-paging-item">
                        <asp:Button ID="Button4" class="tm-paging-link" runat="server" Text="Novels" /></li>
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
            <div id="tm-gallery-page-pizza" class="tm-gallery-page">
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/01.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Pride and Prejudice</h4>
                            <p class="tm-gallery-description">Pride and Prejudice, is an absolute joy to read for teens who are open
                                to the pleasures of 19th-century prose and manners.With its wit, its social precision and, above all, its irresistible heroine,it
                                has proved one of the most enduringly popular novels in the English language. </p>
                           <!-- <p class="tm-gallery-price">$40</p>  -->
                        </figcaption>
                    </figure>



                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/02.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">The Malice of Waves</h4>
                            <p class="tm-gallery-description">The gripping and atmospheric mystery about one boy's disappearance from an isolated
                                but bleakly beautiful island on the edge of the Atlantic Ocean . . .</p>
                           <!-- <p class="tm-gallery-price">$65</p>  -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/03.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Your Soul is a River</h4>
                            <p class="tm-gallery-description">This is a book about the journey of healing from trauma and becoming whole again.
                                Directions: apply to your soul gently, whilst sitting under the stars.</p>
                           <!-- <p class="tm-gallery-price">$30=</p> -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
      
                        <img src="img/gallery/04.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Jerusalem- a Cookbook</h4>
                            <p class="tm-gallery-description">A collection of 120 recipes exploring the flavors of Jerusalem from the New York Times
                                bestselling author of Plenty, one of the most lauded cookbooks of 2011.</p>
                           <!-- <p class="tm-gallery-price">$22</p>  -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/05.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Good or God?</h4>
                            <p class="tm-gallery-description">Good or God?: Why Good Without God Isn't Enough. isn’t another self-help message. This book will do more than ask you to change your behavior.
                                It will empower you to engage with God on a level that will change every aspect of your life.</p>
                            <!-- <p class="tm-gallery-price">$80</p>  -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/06.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">The Passion Within</h4>
                            <p class="tm-gallery-description">Promise Book with a beautiful design and writing space of a journal.
                                Every spread contains themed quotations and Scriptures to inspire your personal reflection, </p>
                           <!-- <p class="tm-gallery-price">$90</p> -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/07.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Milk and Honey</h4>
                            <p class="tm-gallery-description">Milk and honey' is a collection of poetry and prose about survival.
                                About the experience of violence, love, loss, and femininity.To find sweetness in bitter moments in life.</p>
                            <!--  <p class="tm-gallery-price">$34</p>   -->
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/08.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Dreams Unspoken</h4>
                            <p class="tm-gallery-description">Getting it right before it’s too late… Jo Marchal is home again,
                                hoping to mend long-broken fences with her family before time erases that chance forever.</p>
                           <!-- <p class="tm-gallery-price">$25</p> -->
                        </figcaption>
                    </figure>

                </article>
            </div>
            <!-- gallery page 1 -->

            <!-- gallery page 2 -->
            <div id="tm-gallery-page-salad" class="tm-gallery-page hidden">
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/04.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Salad Menu One</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$25</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/03.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Second Title Salad</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$30</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/05.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Third Salad Item</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$45</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/01.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Superior Salad</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$50</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/08.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Sed ultricies dui</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$55 / $60</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/07.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Maecenas eget justo</h4>
                            <p class="tm-gallery-description">Proin eu velit egestas, viverra sapien eget, consequat nunc. Vestibulum tristique</p>
                            <p class="tm-gallery-price">$75</p>
                        </figcaption>
                    </figure>
                </article>
            </div>
            <!-- gallery page 2 -->

            <!-- gallery page 3 -->
            <div id="tm-gallery-page-noodle" class="tm-gallery-page hidden">
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/08.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Noodle One</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$12.50</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/07.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Noodle Second</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$15.50</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/06.jpeg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Third Soft Noodle</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$20.50</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/05.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Aliquam sagittis</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$30.25</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/04.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Maecenas eget justo</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$35.50</p>
                        </figcaption>
                    </figure>
                </article>
                <article class="col-lg-3 col-md-4 col-sm-6 col-12 tm-gallery-item">
                    <figure>
                        <img src="img/gallery/03.jpg" alt="Image" class="img-fluid tm-gallery-img" />
                        <figcaption>
                            <h4 class="tm-gallery-title">Quisque et felis eros</h4>
                            <p class="tm-gallery-description">Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
                            <p class="tm-gallery-price">$40.50</p>
                        </figcaption>
                    </figure>
                </article>

            </div>
            <!-- gallery page 3 -->
        </div>



        <div class="tm-container-inner-2 tm-contact-section">
            <div class="row">
                <div class="col-md-6">
                    <form action="" method="POST" class="tm-contact-form">
                        <div class="form-group">

                            <h3>BookID:</h3>
                            <asp:TextBox ID="TextBox1" class="form-control" runat="server"></asp:TextBox>

                        </div>

                        <div class="form-group">
                            <h3>Quantity:</h3>
                            <asp:TextBox ID="TextBox2" class="form-control" runat="server"></asp:TextBox>

                        </div>

                        <div class="form-group tm-d-flex">

                            <asp:Button ID="Button1" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="AddToCart" />
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <br />

    </main>


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
</asp:Content>
