import React from 'react'
import ServicesCard from './services-card'
import './services.css'
import img1 from './images/log.jpg'
import img2 from './images/two.jpg'
import img3 from './images/three.jpg'
import img4 from './images/four.jpg'
import img5 from './images/five.jpg'
import img6 from './images/six.jpg'
import img7 from './images/seven.jpg'


export default function Services() {

  return (
    <div className="services">
      <div className="max-width">
        <h1>Our Services</h1>
        <div className='serviceCards'>
          <ServicesCard
            ServicesLogo={img1}
            ServicesName="AC Repairing"
          />

          <ServicesCard
            ServicesLogo={img2}
            ServicesName="Web Page Design"
          />

          <ServicesCard
            ServicesLogo={img3}
            ServicesName="Electric Wiring"
          />

          <ServicesCard
            ServicesLogo={img4}
            ServicesName="Plumber"
          />

          <ServicesCard
            ServicesLogo={img5}
            ServicesName="Painter"
          />

          <ServicesCard
            ServicesLogo={img6}
            ServicesName="Loading Furniture"
          />

          <ServicesCard
            ServicesLogo={img7}
            ServicesName="Car Washing"
          />

        </div>


      </div>
    </div>
  )
}
