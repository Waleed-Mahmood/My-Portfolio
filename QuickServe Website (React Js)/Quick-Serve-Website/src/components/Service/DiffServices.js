import React from "react";
import './Servicestyle.css';


const DiffServices=()=>{
    return(
<>


    <section className="bg-light-text-dark fw-bold text-center">
        <h4 className="text-start fw-bold">
            What do you need to be done?
            <a href="#" className="link-dark"><i className="fa fa-times float-end"> </i> </a>
        </h4>
        <div className="row row-cols-1 row-cols-sm-2 row-cols-md-4 m-3 ">
            <div className="col ">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/log.jpg')} alt="DP" className="rounded-circle"/>
                                </div>
                                <div className="col-md-7 col-12">
                                    A.C Reparing
                                </div>
                            </div>

                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body ">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/two.jpg')} alt="DP" className="rounded-circle"/>
                                </div>
                                <div className="col-md-7 col-12">
                                    Web page design
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/three.jpg')} alt="DP" className="rounded-circle "/>
                                </div>
                                <div className="col-md-7 col-12">
                                    Electric home wiring
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title ">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/four.jpg')} alt="DP" className="rounded-circle"/>
                                </div>
                                <div className="col-md-7 col-12">
                                    Plumber
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
        </div>
        <div className="row row-cols-1 row-cols-sm-2 row-cols-md-4 m-3">
            <div className="col">
                <div className="card h-75 ">
                    <div className="card-body">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/five.jpg')} alt="DP" className="rounded-circle"/>
                                </div>
                                <div className="col-md-7 col-12">
                                    Painter
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/six.jpg')} alt="DP" className="rounded-circle "/>
                                </div>
                                <div className="col-md-7 col-12">
                                    loading lugage
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title">
                            <div className="row ">
                                <div className="col-md-5 col-12">
                                    <img src={require('./images/seven.jpg')} alt="DP" className="rounded-circle"/>
                                </div>
                                <div className="col-md-7 col-12">
                                    Car Washing
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>
            <div className="col">
                <div className="card h-75">
                    <div className="card-body">
                        <div className="card-title">
                            See all <i className="fa fa-chevron-down px-2"> </i>
                        </div>

                    </div>
                </div>
            </div>
        </div>
    </section>
    <section className=" m-4">
        <button className="btn btn-secondary btn-lg float-end" type="button">Next</button>
    </section>
    <br />


    </>
    );

}

export default DiffServices;