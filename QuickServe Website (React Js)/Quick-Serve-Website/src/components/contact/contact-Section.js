import React from 'react'
import "./contact.css"
import { Row } from "react-bootstrap"

export default function ContactSection(props) {
  return (
    <Row className="section">
      <Row className="section-title" data-aos="fade-up">
        <h2>{props.sectionTitle}</h2>
        <p>{props.sectionDetails}</p>
      </Row>
    </Row>
  )
}