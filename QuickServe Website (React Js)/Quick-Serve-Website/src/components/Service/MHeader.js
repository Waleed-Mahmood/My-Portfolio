import React from "react";
import './Servicestyle.css';

const MHeader=()=>{
    const mystyle ={
    color: '#fe5f50',
        width: '40px',
        height: '7px',
        opacity: 1
    }

    return(
      <>

          <section className="bg-light text-dark text-sm-start ">
              <nav aria-label="breadcrumb">
                  <ol className="breadcrumb">
                      <li className="breadcrumb-item"><a href="#." className="link-dark">Home</a></li>
                      <li className="breadcrumb-item active" aria-current="page"> Find a Expert</li>
                  </ol>
              </nav>
          </section>
          <section className="bg-light text-dark text-sm-start">
              <div className="row pt-5">
                  <div className="col-12 col-md-7">
                      <h1 className="display-4 fw-bolder" style={{color: '#fe5f50'}}><strong>Find a Expert you'll
                          love</strong></h1>
                      <hr style={mystyle} />
                          <p className="fs-5">
                              We have professional workers in over <a href="#" className="link-dark text-muted">
                              Kamal-kam</a>
                              <br />
                                  <a href="#." className="link-dark text-muted">Sign up</a> to find the perfect expert
                                  for whatever you need.
                          </p>
                  </div>
                  <div className="col-5 d-none d-md-block">
                      <img src={require('./images/ss.png')} alt="" className="img-fluid float-end"/>
                  </div>
              </div>
          </section>


      </>
    );
}

export default MHeader;