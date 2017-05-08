// swift-tools-version:3.1

import PackageDescription

let package = Package(
    name: "KittenCTLS",
    pkgConfig: "ctls",
    providers: [
        .Brew("ctls"),
        .Apt("ctls")
    ]
)
