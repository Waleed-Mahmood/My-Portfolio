import React from 'react'
import "./contact.css"
import { Row, Col, Form, FloatingLabel, InputGroup, Button } from "react-bootstrap"

export default function ContactForm() {
  return (

    <Col xs={12} md={6} lg={8} data-aos="fade-left" data-aos-delay="200">
      <Form className="form">
        <Row className="mb-4">
          <Form.Group as={Col} size="lg" sm={12} md={6} controlId="formGridName">
            <Form.Control type="text" placeholder="Your Name" />
          </Form.Group>

          <Form.Group as={Col} md={6} sm={12} size="lg" controlId="formGridEmail">
            <InputGroup className="mb-2">
              <InputGroup.Text>@</InputGroup.Text>
              <Form.Control type="email" placeholder="Your Email" />
            </InputGroup>
          </Form.Group>

        </Row>

        <Row className="mb-4">
          <Form.Group md={6} controlId="formGridSubject">
            <Form.Control placeholder="Enter Subject" />
          </Form.Group>
        </Row>

        <Row className="mb-4">
          <Form.Group md={6} controlId="formGridAddress">
            <Form.Control placeholder="Street, Town, Apartment, studio, or floor" />
          </Form.Group>
        </Row>

        <Row className="mb-4">
          <Form.Group md={5} as={Col} controlId="formGridState">
            <Form.Select defaultValue="Punjab">
              <option>Punjab</option>
              <option>Sindh</option>
              <option>Balochistan</option>
              <option>Khyber Pakhtunkhwa</option>
              <option>FATA</option>
            </Form.Select>
          </Form.Group>

          <Form.Group md={4} as={Col} controlId="formGridCity">
            <Form.Control placeholder="City" />
          </Form.Group>

          <Form.Group as={Col} controlId="formGridZip">
            <Form.Control placeholder="Zip" />
          </Form.Group>
        </Row>

        <Row className="mb-4">
          <FloatingLabel md={6} controlId="floatingTextarea">
            <Form.Control
              as="textarea"
              style={{ height: '125px' }}
              placeholder="Leave a comment here"
            />
          </FloatingLabel>
        </Row>

        <Row>
          <Button
            className="rounded-pill"
           
            size="md">

            Send Message
          </Button>
        </Row>
      </Form>
    </Col>
  )
}