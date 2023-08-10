import React from "react";
import './Servicestyle.css';


const SHeader=()=>{
return(
    <>
        <section>
            <nav className="navbar navbar-expand-lg navbar-light bg-light fw-bold">
                <div className="container-fluid">
                    <a href="#." className="navbar-brand">
                        <img src={require('./images/klogo.jpg')} height={56} />
                    </a>
                    <button className="navbar-toggler" type="button" data-bs-toggle="collapse"
                            data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent"
                            aria-expanded="false" aria-label="Toggle navigation">
                        <span className="navbar-toggler-icon"> </span>
                    </button>
                    <div className="collapse navbar-collapse" id="navbarSupportedContent">
                        <ul className="navbar-nav mb-lg-0">
                            <li className="nav-item">
                                <a className="nav-link active" href="#">Categories</a>
                            </li>
                            <li className="nav-item">
                                <a className="nav-link active" href="#">How it works</a>
                            </li>
                            <li className="nav-item">
                                <a className="nav-link active" href="#">Find an Expert</a>
                            </li>
                            <li className="nav-item">
                                <a className="nav-link active" href="#">Studio</a>
                            </li>
                        </ul>
                        <ul className="navbar-nav  mb-2 mb-lg-0 ms-auto">
                            <li className="nav-item">
                                <a className="nav-link active" href="#"><i className="bi bi-telephone-fill"> </i> 1800
                                    513 1678</a>
                            </li>
                            <li className="nav-item navbar-">
                                <a className="nav-link active" href="#.">Login </a>
                            </li>
                        </ul>
                    </div>
                </div>

            </nav>
        </section>


    </>
);
}

export default SHeader;