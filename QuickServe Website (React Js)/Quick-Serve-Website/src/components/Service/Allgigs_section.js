import React from "react";
import './Servicestyle.css';
import Displaycard from './cards';
import img1 from './images/expert/plumber2.1.jpg'
import img2 from './images/expert/plumber.jpg'
import img3 from './images/expert/motor2.1.png'
import img4 from './images/expert/motor.jpg'
import img5 from './images/expert/woodworks1.jpg'
import img6 from './images/expert/wood.png'
import img7 from './images/expert/elogo1.jpg'
import img8 from './images/expert/ele.jpg'
import img9 from './images/expert/paint2.jpg'
import img10 from './images/expert/painter.jpeg'
import img11 from './images/expert/clean1.jpg'
import img12 from './images/expert/clean_service.jpg'
import img13 from './images/expert/idelogo2.1.jpg'
import img14 from './images/expert/ide.jpeg'
import img15 from './images/expert/web2.jpg'
import img16 from './images/expert/web.jpg'

export default function Allgigs_Section() {
    return (
        <div className="header">
            <div className="col-12 mb-3">
                <span className="fs-4 fw-bold">Services Provider</span>

                <button className="btn  float-end border-bottom">See all results
                    <i className="bi bi-arrow-right"> </i></button>
            </div>
            <div className="row row-cols-1 row-cols-sm-3 mb-4" >
                <div className="col">
                    <Displaycard Logo={img1} Company="Zubair plumbers" Picture={img2} />
                </div>
                <div className="col">
                    <Displaycard Logo={img3} Company="The Auto Clinic" Picture={img4} />
                </div>
                <div className="col">
                    <Displaycard Logo={img5} Company="Accents Woodwork" Picture={img6} />
                </div>
            </div>
            <div className="row">
                <div className="col-10 mb-4">
                </div>
            </div>
            <div className="row row-cols-1 row-cols-sm-3 mb-4">
                <div className="col">
                    <Displaycard Logo={img7} Company="Nadeem electonics" Picture={img8} />
                </div>
                <div className="col">
                    <Displaycard Logo={img9} Company="Colorful visions" Picture={img10} />
                </div>
                <div className="col">
                    <Displaycard Logo={img11} Company="Express 24 Clean" Picture={img12} />
                </div>
            </div>
            <div className="row">
                <div className="col-10 mb-4">
                </div>
            </div>
            <div className="row row-cols-1 row-cols-sm-3 mb-4">
                <div className="col">
                    <Displaycard Logo={img13} Company="Interior Charmer" Picture={img14} />
                </div>
                <div className="col">
                    <Displaycard Logo={img15} Company="Wonder Web Studio" Picture={img16} />
                </div>
            </div>

        </div>
    );
}