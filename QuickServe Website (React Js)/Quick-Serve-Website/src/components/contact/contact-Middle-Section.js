import React from 'react'
import "./contact.css"
import ContactINFO from './contact-Info'
import { Col } from "react-bootstrap"

export default function ContactMiddleSection() {
  return (
    <Col lg={4} md={6} sm={12} className="INFO" data-aos="fade-right" data-aos-delay="100">
      <ContactINFO
        iconName="Location:"
        iconDetail="852-B Milaad St, Block B Faisal Town, Lahore, Punjab 54770"
        link="https://g.page/FASTNULahore?share"
        icon="bi bi-geo-alt"
      />

      <ContactINFO
        iconName="Email:"
        iconDetail="QuickServe@gmail.com"
        link="mailto:info@yoursite.com"
        icon="bi bi-envelope"
      />

      <ContactINFO
        iconName="Call:"
        iconDetail="+92 321-6467112"
        link="tel://1234567920"
        icon="bi bi-phone"
      />
    </Col>
  )
}