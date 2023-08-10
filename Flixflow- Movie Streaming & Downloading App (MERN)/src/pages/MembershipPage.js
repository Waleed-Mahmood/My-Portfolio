import React from 'react';
import { useNavigate } from 'react-router-dom';
import './MembershipPage.css';

const MembershipPage = () => {
    const navigate = useNavigate();

    const handleCardPayment = () => {
        // Handle card payment logic
        // Redirect to payment confirmation page
        navigate('/Payment-Confirmation');
    };

    var tick = document.querySelector(".tick span");
    var tick_mark = document.querySelector(".tick span i");
    tick.addEventListener('click', function () {

        tick.classList.toggle('p-blue');
        tick_mark.classList.toggle('d-none');
    });


    // document.addEventListener('DOMContentLoaded', () => {
    //     for (const el of document.querySelectorAll("[placeholder][data-slots]")) {
    //         const pattern = el.getAttribute("placeholder"),
    //             slots = new Set(el.dataset.slots || "_"),
    //             prev = (j => Array.from(pattern, (c, i) => slots.has(c) ? j = i + 1 : j))(0),
    //             first = [...pattern].findIndex(c => slots.has(c)),
    //             accept = new RegExp(el.dataset.accept || "\\d", "g"),
    //             clean = input => {
    //                 input = input.match(accept) || [];
    //                 return Array.from(pattern, c =>
    //                     input[0] === c || slots.has(c) ? input.shift() || c : c
    //                 );
    //             },
    //             format = () => {
    //                 const [i, j] = [el.selectionStart, el.selectionEnd].map(i => {
    //                     i = clean(el.value.slice(0, i)).findIndex(c => slots.has(c));
    //                     return i < 0 ? prev[prev.length - 1] : back ? prev[i - 1] || first : i;
    //                 }); el.value = clean(el.value).join``; el.setSelectionRange(i, j); back = false;
    //             }; let back = false; el.addEventListener("keydown", (e) => back = e.key === "Backspace");
    //         el.addEventListener("input", format);
    //         el.addEventListener("focus", format);
    //         el.addEventListener("blur", () => el.value === pattern && (el.value = ""));
    //     }
    // });

    return (
        <>

            <div class="card-container">
                <h1> Become Member of our Site. Donate 3$ </h1>
                <div class="card">
                    <div class="top">
                        <h3>Add new card</h3>
                        <hr />
                    </div>
                    <div class="card-details">
                        <input type="text" placeholder="0000 0000 0000 0000" data-slots="0" data-accept="\d" size="19" />
                        <span>Card Number</span>
                        <i class="fa fa-credit-card"></i> </div>
                    <div class="exp-cvv">
                        <div class="card-details"> <input type="text" placeholder="mm/yyyy" data-slots="my" /> <span>Expiry date</span> <i class="fa fa-calendar"></i> </div>
                        <div class="card-details"> <input type="text" placeholder="000" data-slots="0" data-accept="\d" size="3" /> <span>CVV</span> <i class="fa fa-info-circle"></i> </div>
                    </div>
                    <div class="card-details mt-25"> <input type="text" placeholder="Enter cardholder's full name" /> <span>Card Holder Name</span> </div>
                    <div class="tick"> <span><i class="fa fa-check d-none"></i></span>
                        <p>Save card</p>
                    </div>
                    <div class="button"> <button onClick={handleCardPayment}>Add card</button> </div>
                </div>
            </div>
        </>
    );
};

export default MembershipPage;