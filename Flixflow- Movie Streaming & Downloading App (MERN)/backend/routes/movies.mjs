import express from "express";
import db from "../db/conn.mjs";
import { ObjectId } from "mongodb";

const router = express.Router();

// Get all movies
router.get("/", async (req, res) => {
    try {
        const collection = await db.collection("movies");
        const results = await collection.find({}).toArray();
        res.send(results).status(200);
    } catch (error) {
        res.status(500).send("Error retrieving movies");
    }
});

// Get a single movie by id
router.get("/:id", async (req, res) => {
    try {
        const collection = await db.collection("movies");
        const query = { _id: new ObjectId(req.params.id) };
        const result = await collection.findOne(query);

        if (!result) {
            res.status(404).send("Movie not found");
        } else {
            res.send(result).status(200);
        }
    } catch (error) {
        res.status(500).send("Error retrieving movie");
    }
});

// Create a new movie
router.post("/", async (req, res) => {
    try {
        const newMovie = {
            name: req.body.name,
            position: req.body.position,
            level: req.body.level,
        };

        const collection = await db.collection("movies");
        const result = await collection.insertOne(newMovie);

        res.status(201).send(result.ops[0]);
    } catch (error) {
        res.status(500).send("Error creating movie");
    }
});

// Update a movie by id
router.patch("/:id", async (req, res) => {
    try {
        const query = { _id: new ObjectId(req.params.id) };
        const updates = {
            $set: {
                name: req.body.name,
                position: req.body.position,
                level: req.body.level,
            },
        };

        const collection = await db.collection("movies");
        const result = await collection.updateOne(query, updates);

        res.send(result).status(200);
    } catch (error) {
        res.status(500).send("Error updating movie");
    }
});

// Delete a movie
router.delete("/:id", async (req, res) => {
    try {
        const query = { _id: new ObjectId(req.params.id) };

        const collection = await db.collection("movies");
        const result = await collection.deleteOne(query);

        res.send(result).status(200);
    } catch (error) {
        res.status(500).send("Error deleting movie");
    }
});

export default router;
