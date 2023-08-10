import React from "react"
import "./contact.css"
import ContactForm from "./contact-Form"
import ContactSection from "./contact-Section"
import ContactMiddleSection from "./contact-Middle-Section"
import { Container, Col, Row } from "react-bootstrap"


export default function Contact() {
  return (

    <div id="contact" className="contact">
      <ContactSection
        sectionTitle="CONTACT"
        sectionDetails="CONTACT US"
      />
      
      <Row lg={12}>
        <ContactMiddleSection />

        <ContactForm />

      </Row>
    </div >


  )
}


