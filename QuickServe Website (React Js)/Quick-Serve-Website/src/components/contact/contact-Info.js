import React from 'react'
import "./contact.css"
import { Row, Col } from "react-bootstrap"

export default function ContactINFO(props) {
  return (

    <Row className="info">
      <Col xs={2} md={2} lg={2} className="info-icon">
        <a href={props.link}><i className={props.icon}></i></a>
      </Col>
      <Col>
        <Row className="info-detail">
          <h4>{props.iconName}</h4>
          <p><a href={props.link}>{props.iconDetail}</a></p>
        </Row>
      </Col>
    </Row>

  )
}