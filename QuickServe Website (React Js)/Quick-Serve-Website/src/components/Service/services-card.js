import React from 'react'
import "./services.css"
export default function ServicesCard(props) {
  return (
    <>
      <div className="card">
        <div className="box">
          <img
            src= {props.ServicesLogo} 
            alt="" 
            style={{width: "100px", height: "60px"}}
            />
          
          <h3>
            {props.ServicesName}
          </h3>
        </div>
      </div>
    </>
  )
}